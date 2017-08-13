package com.example.snakegame;

import java.util.BitSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;

import android.R.bool;
import android.R.integer;
import android.app.DownloadManager.Query;
import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Rect;
import android.util.AttributeSet;
import android.view.View;

class DensityUtil {  
	  
    /** 
     * �����ֻ��ķֱ��ʴ� dp �ĵ�λ ת��Ϊ px(����) 
     */  
    public static float dip2px(Context context, float dpValue) {  
        final float scale = context.getResources().getDisplayMetrics().density;  
        return dpValue * scale;  
    }  
  
    /** 
     * �����ֻ��ķֱ��ʴ� px(����) �ĵ�λ ת��Ϊ dp 
     */  
    public static float px2dip(Context context, float pxValue) {  
        final float scale = context.getResources().getDisplayMetrics().density;  
        return pxValue / scale;  
    }  
} 

public class SnakeView extends View {
	private int mBlocksize;			//��Ԫ��Ĵ�С
	private int mWidth,mHeight;		//��Ϸ����Ŀ�Ⱥ͸߶�
	private int mOffsetX,mOffsetY;			//��Ϸ������ʼƫ��λ��
	private int mSnakeLen;			//�ߵĳ���
	private LinkedList<Rect> mSnakeXY ;		//�ߵ�����
	private int mSnakeDir;			//�ߵķ���
	private int mFoodX,mFoodY;			//ʳ���X��Y����
	private int mFoodCnt;				//�Ѿ��Ե���ʳ�����
	private boolean mIsEated;
	
	DensityUtil densityUtil = new DensityUtil();
	private float multiplePX;
	Paint ptBackground = new Paint();	//���ڻ��Ʊ����Ļ���
	Paint ptHead = new Paint();		//���ڻ�����ͷ�Ļ���
	Paint ptBody = new Paint();		//���ڻ�������Ļ���
	Paint ptFood = new Paint();		//���ڻ���ʳ��Ļ���
	Paint ptBorder = new Paint();		//���ڻ�����Ϸ�߿�Ļ���
		
	public static final int DIR_UP = 0;		//�߷�������
	public static final int DIR_RIGHT = 1;	//�߷�������
	public static final int DIR_DOWN = 2;	//�߷�������
	public static final int DIR_LEFT = 3;	//�߷�������

	public SnakeView(Context context, AttributeSet attrs, int defStyle) {
		super(context, attrs, defStyle);
		// TODO Auto-generated constructor stub
		InitGame();
	}
	public SnakeView(Context context, AttributeSet attrs) {
		super(context, attrs);
		// TODO Auto-generated constructor stub
		InitGame();
	}
	public SnakeView(Context context) {
		super(context);
		// TODO Auto-generated constructor stub
		InitGame();
	}
	
	/**
	 *  �趨����Paint����ɫ��
		�趨�ߵĳ�ʼ���ȣ�
		�趨�ߵĳ�ʼλ�ã�
		�趨�ߵĳ�ʼ����
		�趨ʳ��ĳ�ʼλ�á�
	 */
	public void InitGame(){
		ptBackground.setARGB(255 ,240 ,255 ,255);
		ptHead.setColor(Color.RED);
		ptBody.setColor(Color.YELLOW);
		ptFood.setColor(Color.BLUE);
		ptBorder.setARGB(255,139, 69, 19);
		//��Ļ��С����
		multiplePX = (densityUtil.dip2px(getContext(), 1))/2;
		mBlocksize = (int) (20*multiplePX);
		mSnakeLen = 4;
		//����ͷ������ͷ
		mSnakeXY = new LinkedList<Rect>();
		for(int i=1; i<mSnakeLen+1; i++){
			Rect rect = new Rect(i*mBlocksize,
					mBlocksize,
					(i+1)*mBlocksize,
					2*mBlocksize);
			mSnakeXY.addFirst(rect); 
		}
		mSnakeDir = DIR_RIGHT;
		
		mFoodX = 10;
		mFoodY = 10;
		mFoodCnt = 0;
		mIsEated = false;
	}
	
	/**
	 * Ϊ���Զ�������Ϸ����������дonSizeChanged�������÷����ڿؼ���С�����仯ʱ�ᱻ�Զ����á�
	 */
	protected void onSizeChanged(int w, int h, int oldw, int oldh) {
		// TODO Auto-generated method stub
		super.onSizeChanged(w, h, oldw, oldh);
			
		mWidth = w / mBlocksize - 1;
		mHeight = h / mBlocksize - 1;
		mOffsetX = (w - mWidth*mBlocksize) / 2;
		mOffsetY = (h - mHeight*mBlocksize) / 2;
	}

	/**
	 * ÿ���ߵ��ƶ������ػ滭��
	 * ��дonDraw������������ϷԪ�صĻ��ƣ�
		��Ϸ���򱳾���
		��Ϸ����߿�
		ʳ�
		��ͷ��
		�����塣
	 */
	@Override
	protected void onDraw(Canvas canvas) {
		// TODO �Զ����ɵķ������
		super.onDraw(canvas);
		
		mWidth = 33;
		mHeight = 35;
		//��Ϸ����
		for(int i=0; i<mHeight; i++){
        	for(int j=0; j<mWidth; j++){
        		Rect rect = new Rect(j*mBlocksize,i*mBlocksize,
        							(j+1)*mBlocksize,(i+1)*mBlocksize);
        		canvas.drawRect(rect, ptBackground);
        	}
        }
		//��Ϸ���߿�
		for(int i=0; i<mWidth; i++){
			Rect rect1 = new Rect(i*mBlocksize,0,
								(i+1)*mBlocksize,(1)*mBlocksize);
			Rect rect2 = new Rect(i*mBlocksize,(mHeight-1)*mBlocksize,
								(i+1)*mBlocksize,mHeight*mBlocksize);
			canvas.drawRect(rect1, ptBorder);
			canvas.drawRect(rect2, ptBorder);
		}
		for(int i=0; i<mHeight; i++){
			Rect rect1 = new Rect(0,i*mBlocksize,
								1+mBlocksize,(i+1)*mBlocksize);
			Rect rect2 = new Rect((mWidth-1)*mBlocksize,
					i*mBlocksize,
					mWidth*mBlocksize,
					(i+1)*mBlocksize);
			canvas.drawRect(rect1, ptBorder);
			canvas.drawRect(rect2, ptBorder);
		}
		//����
		go();
		for(Rect rect:mSnakeXY){
			canvas.drawRect(rect, ptBody);
		}
		//��ͷ
		canvas.drawRect(mSnakeXY.getFirst(), ptHead);
		
		//ʳ����������:��ͷ��ʳ��λ���غϣ�ʳ����������ɣ�����ʳ��λ�ò���
		if (mIsEated) {
			setRandom();
			mIsEated=false;
		}
		Rect foodRect = new Rect(mFoodX*mBlocksize,mFoodY*mBlocksize,
								(mFoodX+1)*mBlocksize,(mFoodY+1)*mBlocksize);
		canvas.drawRect(foodRect, ptFood);
	}
	/**
	 * �ж����Ƿ�Ե�ʳ��Ե�ʳ�������ߵĳ��ȣ�ʳ��������ӣ�û�Ե�ʳ���������ƶ�
	 */
	protected void go() {
		Rect snakeHeadRect = mSnakeXY.getFirst();
		if (snakeHeadRect.left==mFoodX*mBlocksize && snakeHeadRect.top==mFoodY*mBlocksize) {
			mIsEated = true;
			mFoodCnt++;
			snakeMoveAndEat(true);
		}else {
			snakeMoveAndEat(false);
		}
	}
	
	/**
	 * ��ȡ�Ե���ʳ�����
	 */
	protected Integer getEatedFood() {
		return mFoodCnt;
	}
	
	/**
	 * ���߱߳ԣ��ߵ������ͷ���ݷ�����ǰ�ƣ�Ҳ����������ͷ�ڵ㣻
	 * ���û�гԵ�ʳ�ɾ������β�ڵ㣻��������β�ڵ㲻ɾ��
	 */
	protected void snakeMoveAndEat(boolean isEated) {
		Rect headRect = mSnakeXY.getFirst();
		Rect newHeadRect = new Rect();
		switch (mSnakeDir) {
		case DIR_LEFT:
			newHeadRect.set(headRect.left-mBlocksize,headRect.top,
								headRect.right-mBlocksize,headRect.bottom);
			mSnakeXY.addFirst(newHeadRect);
			break;
		case DIR_RIGHT:
			newHeadRect.set(headRect.left+mBlocksize,headRect.top,
					headRect.right+mBlocksize,headRect.bottom);
			mSnakeXY.addFirst(newHeadRect);
			break;
		case DIR_UP:
			newHeadRect.set(headRect.left,headRect.top-mBlocksize,
					headRect.right,headRect.bottom-mBlocksize);
			mSnakeXY.addFirst(newHeadRect);
			break;
		case DIR_DOWN:
			newHeadRect.set(headRect.left,headRect.top+mBlocksize,
					headRect.right,headRect.bottom+mBlocksize);
			mSnakeXY.addFirst(newHeadRect);
			break;
		default:
			break;
		}
		if (!isEated) {
			mSnakeXY.removeLast();
		}
	}
	
	/**
	 * �ж����Ƿ�������
	 * 1��ײ���Լ�
	 * 2��ײ��ǽ
	 */
	protected boolean isDead(){
		boolean retFlag = false;
		int left = mSnakeXY.getFirst().left;
		int top = mSnakeXY.getFirst().top;
		if (left==0 || left==(mWidth-1)*mBlocksize || 
				top==0 || top==(mHeight-1)*mBlocksize) {
			retFlag=true;
		}
		Rect headRect = mSnakeXY.removeFirst();
		for(Rect rect:mSnakeXY){
			if (headRect.equals(rect)) {
				retFlag=true;
			}
		}
		mSnakeXY.addFirst(headRect);
		return retFlag;
	}
	/**
	 * �����û�����ķ���ť�������ƶ���������
	 */
	protected void setDIR(int DIR) {
		switch (DIR) {
		case DIR_LEFT:
			mSnakeDir = DIR_LEFT;
			break;
		case DIR_RIGHT:
			mSnakeDir = DIR_RIGHT;
			break;
		case DIR_UP:
			mSnakeDir = DIR_UP;
			break;
		case DIR_DOWN:
			mSnakeDir = DIR_DOWN;
			break;
		default:
			break;
		}
	}
	
	/**
	 * ��ȡ�ߵ�ǰ�ƶ�����
	 */
	protected int getDIR() {
		return this.mSnakeDir;
	}
	
	/**
	 *�������ʳ�� �����������ǽ�壬��������
	 */
	protected void setRandom() {
		boolean flag = true;
		while(flag){
			flag = false;
			double xFloat = Math.random();
			double yFloat = Math.random();
			mFoodX = (int)(xFloat*mWidth-1);
			mFoodY = (int)(yFloat*mHeight-1);
			if (mFoodX!=0 && mFoodY!=0) {
				for(Rect rect:mSnakeXY){
					if(mFoodX*mBlocksize==rect.left && mFoodY*mBlocksize==rect.top){
						flag = true;
						break;
					}
				}
			}else{
				flag = true;
			}
		}
	}
}
