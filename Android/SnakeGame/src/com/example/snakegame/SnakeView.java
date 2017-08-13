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
     * 根据手机的分辨率从 dp 的单位 转成为 px(像素) 
     */  
    public static float dip2px(Context context, float dpValue) {  
        final float scale = context.getResources().getDisplayMetrics().density;  
        return dpValue * scale;  
    }  
  
    /** 
     * 根据手机的分辨率从 px(像素) 的单位 转成为 dp 
     */  
    public static float px2dip(Context context, float pxValue) {  
        final float scale = context.getResources().getDisplayMetrics().density;  
        return pxValue / scale;  
    }  
} 

public class SnakeView extends View {
	private int mBlocksize;			//单元格的大小
	private int mWidth,mHeight;		//游戏区域的宽度和高度
	private int mOffsetX,mOffsetY;			//游戏区域起始偏移位置
	private int mSnakeLen;			//蛇的长度
	private LinkedList<Rect> mSnakeXY ;		//蛇的坐标
	private int mSnakeDir;			//蛇的方向
	private int mFoodX,mFoodY;			//食物的X和Y坐标
	private int mFoodCnt;				//已经吃到的食物个数
	private boolean mIsEated;
	
	DensityUtil densityUtil = new DensityUtil();
	private float multiplePX;
	Paint ptBackground = new Paint();	//用于绘制背景的画笔
	Paint ptHead = new Paint();		//用于绘制蛇头的画笔
	Paint ptBody = new Paint();		//用于绘制蛇身的画笔
	Paint ptFood = new Paint();		//用于绘制食物的画笔
	Paint ptBorder = new Paint();		//用于绘制游戏边框的画笔
		
	public static final int DIR_UP = 0;		//蛇方向：向上
	public static final int DIR_RIGHT = 1;	//蛇方向：向右
	public static final int DIR_DOWN = 2;	//蛇方向：向下
	public static final int DIR_LEFT = 3;	//蛇方向：向左

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
	 *  设定各个Paint的颜色；
		设定蛇的初始长度；
		设定蛇的初始位置；
		设定蛇的初始方向；
		设定食物的初始位置。
	 */
	public void InitGame(){
		ptBackground.setARGB(255 ,240 ,255 ,255);
		ptHead.setColor(Color.RED);
		ptBody.setColor(Color.YELLOW);
		ptFood.setColor(Color.BLUE);
		ptBorder.setARGB(255,139, 69, 19);
		//屏幕大小适配
		multiplePX = (densityUtil.dip2px(getContext(), 1))/2;
		mBlocksize = (int) (20*multiplePX);
		mSnakeLen = 4;
		//链表头部是蛇头
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
	 * 为了自动计算游戏区域，我们重写onSizeChanged方法，该方法在控件大小发生变化时会被自动调用。
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
	 * 每次蛇的移动都是重绘画布
	 * 重写onDraw方法，进行游戏元素的绘制：
		游戏区域背景；
		游戏区域边框；
		食物；
		蛇头；
		蛇身体。
	 */
	@Override
	protected void onDraw(Canvas canvas) {
		// TODO 自动生成的方法存根
		super.onDraw(canvas);
		
		mWidth = 33;
		mHeight = 35;
		//游戏区域
		for(int i=0; i<mHeight; i++){
        	for(int j=0; j<mWidth; j++){
        		Rect rect = new Rect(j*mBlocksize,i*mBlocksize,
        							(j+1)*mBlocksize,(i+1)*mBlocksize);
        		canvas.drawRect(rect, ptBackground);
        	}
        }
		//游戏区边框
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
		//蛇身
		go();
		for(Rect rect:mSnakeXY){
			canvas.drawRect(rect, ptBody);
		}
		//蛇头
		canvas.drawRect(mSnakeXY.getFirst(), ptHead);
		
		//食物的随机生成:蛇头和食物位置重合，食物再随机生成；否则食物位置不变
		if (mIsEated) {
			setRandom();
			mIsEated=false;
		}
		Rect foodRect = new Rect(mFoodX*mBlocksize,mFoodY*mBlocksize,
								(mFoodX+1)*mBlocksize,(mFoodY+1)*mBlocksize);
		canvas.drawRect(foodRect, ptFood);
	}
	/**
	 * 判断蛇是否吃到食物，吃到食物增加蛇的长度，食物个数增加，没吃到食物蛇正常移动
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
	 * 获取吃到的食物个数
	 */
	protected Integer getEatedFood() {
		return mFoodCnt;
	}
	
	/**
	 * 边走边吃：蛇的链表表头根据方向向前移，也就是新增表头节点；
	 * 如果没有吃到食物，删除链表尾节点；否则链表尾节点不删除
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
	 * 判断蛇是否死亡：
	 * 1：撞到自己
	 * 2：撞到墙
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
	 * 根据用户点击的方向按钮进行蛇移动方向设置
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
	 * 获取蛇当前移动方向
	 */
	protected int getDIR() {
		return this.mSnakeDir;
	}
	
	/**
	 *随机生成食物 ，避免出现在墙体，蛇身体内
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
