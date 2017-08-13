package com.example.snakegame;

import java.util.Timer;
import java.util.TimerTask;

import android.R.integer;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.provider.ContactsContract.CommonDataKinds.Event;
import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.SharedPreferences;
import android.text.StaticLayout;
import android.view.Menu;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.View.OnLongClickListener;
import android.view.View.OnTouchListener;
import android.view.Window;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity {
	public static final int DIR_UP = 0;		//�߷�������
	public static final int DIR_RIGHT = 1;	//�߷�������
	public static final int DIR_DOWN = 2;	//�߷�������
	public static final int DIR_LEFT = 3;	//�߷�������
	
	private Button pauseButton;
	private Button startButton;
	private Button leftButton;
	private Button rightButton;
	private Button upButton;
	private Button downButton;
	private TextView scoreTextView;
	private TextView maxScoreTextView;
	
	private Timer mTimer = null;  				//��ʱ��
	private TimerTask mTimerTask = null;  			//��ʱ������
	private Handler mHandler = null; 				//������Ϣ��Handler
	private final int SNAKE_MOVE = 1;			//���ƶ��Ķ�ʱ����Ϣ��

	private int mGameStatus;
	private final int STATUS_RUN  = 1;			//��Ϸ״̬������
	private final int STATUS_DEAD = 2;			//��Ϸ״̬������
	private final int STATUS_PAUSE= 3;			//��Ϸ״̬����ͣ

	private final int startSpeed = 400;//snake��ʼ�ٶȣ����Ƕ�ʱ����ʱ����
	private final int everyAddSpeed = 15;//���ٵ�λ
	private final int addSpeedNum = 3;//ÿ�Ե�n��ʳ���ʱ������everyAddSpeed��λ��ʱ��
	private Integer mFoodCnt = 0;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		setContentView(R.layout.activity_main);
		
		final SnakeView snakeView = (SnakeView)findViewById(R.id.snakeView);
		
		pauseButton = (Button)findViewById(R.id.pause);
		startButton = (Button)findViewById(R.id.start);
		upButton = (Button)findViewById(R.id.up);
		downButton = (Button)findViewById(R.id.down);
		leftButton = (Button)findViewById(R.id.left);
		rightButton = (Button)findViewById(R.id.right);
		scoreTextView = (TextView)findViewById(R.id.scoreNum);
		maxScoreTextView = (TextView)findViewById(R.id.maxScoreNum);
		
		mGameStatus = STATUS_PAUSE;
		
		class DirButtonListener implements OnClickListener{
			public void onClick(View arg0) {
				// TODO �Զ����ɵķ������
				int buttonId = ((Button)arg0).getId();
				int currentDIR = snakeView.getDIR();
				if (mGameStatus==STATUS_RUN) {
					switch (buttonId) {
					case R.id.left:
						if (currentDIR == DIR_DOWN || currentDIR == DIR_UP)
							snakeView.setDIR(DIR_LEFT);
						break;
					case R.id.right:
						if (currentDIR == DIR_DOWN || currentDIR == DIR_UP)
							snakeView.setDIR(DIR_RIGHT);
						break;
					case R.id.up:
						if (currentDIR == DIR_LEFT || currentDIR == DIR_RIGHT)
							snakeView.setDIR(DIR_UP);
						break;
					case R.id.down:
						if (currentDIR == DIR_LEFT || currentDIR == DIR_RIGHT)
							snakeView.setDIR(DIR_DOWN);
						break;
					default:
						break;
					}
				}
			}
		}
		DirButtonListener dirButtonListener = new DirButtonListener();
		leftButton.setOnClickListener(dirButtonListener);
		rightButton.setOnClickListener(dirButtonListener);
		upButton.setOnClickListener(dirButtonListener);
		downButton.setOnClickListener(dirButtonListener);
		
		class MaxScore{
			private SharedPreferences.Editor editor;//��߷ֱ༭��
			private SharedPreferences preferences;
			public void set(Integer maxScore){
				editor = getSharedPreferences("data",MODE_PRIVATE).edit();
				editor.putInt("maxScore", maxScore.intValue());
				editor.commit();
			}
			public Integer get(){
				preferences = getSharedPreferences("data", MODE_PRIVATE);
				return preferences.getInt("maxScore", 0);
			}
		}
		
		final MaxScore maxScore = new MaxScore();
		maxScoreTextView.setText(maxScore.get().toString());
		
		//��ʱ����������
		mHandler = new Handler(){
			public void handleMessage(android.os.Message msg) {
				switch (msg.what) {
				case SNAKE_MOVE:
					//�ж��Ƿ�����
					if (snakeView.isDead()) {
						mGameStatus=STATUS_DEAD;
						mTimer.cancel();
						Toast.makeText(getApplicationContext(), 
							"�÷֣�"+scoreTextView.getText().toString(), 
							Toast.LENGTH_LONG).show();
					}else{
						//ˢ��view
						snakeView.invalidate();
						//ʵʱ���·���
						mFoodCnt = snakeView.getEatedFood();
						if (scoreTextView.getText().toString()!=mFoodCnt.toString()) {
							scoreTextView.setText(mFoodCnt+"");
						}
						if (mFoodCnt>maxScore.get().intValue()) {
							maxScore.set(mFoodCnt);
							maxScoreTextView.setText(mFoodCnt.toString());
						}
						if (mFoodCnt/addSpeedNum>0 && mFoodCnt%addSpeedNum==0) {
							int currentSpeed = startSpeed-everyAddSpeed*(mFoodCnt/addSpeedNum);
							mTimer.cancel();
							taskStart(currentSpeed);
						}
						
						
					}
					break;
				default:
					break;
				}
			};
		};
		
		startButton.setOnClickListener(new OnClickListener() {
			public void onClick(View arg0) {
				// TODO �Զ����ɵķ������
				
				if (mGameStatus==STATUS_PAUSE || mGameStatus==STATUS_DEAD) {
					if (mGameStatus==STATUS_DEAD) {//����״̬���ٵ㿪ʼҪ������Ϸ��ʼ��
						snakeView.InitGame();
					}
					taskStart(startSpeed);
					mGameStatus=STATUS_RUN;
				}
			}
		});
		pauseButton.setOnClickListener(new OnClickListener() {
			public void onClick(View arg0) {
				// TODO �Զ����ɵķ������
				if (mGameStatus==STATUS_RUN) {
					mTimer.cancel();
					mGameStatus=STATUS_PAUSE;
				}
			}
		});
	}
	
	/**
	 * �˳���ť�ļ�������ʵ�ֵ���
	 */
	@Override
	public void onBackPressed() {
		// TODO �Զ����ɵķ������
		if(mGameStatus==STATUS_RUN){
			mTimer.cancel();
		}
		AlertDialog.Builder dialog = new AlertDialog.Builder
				(MainActivity.this);
				dialog.setTitle("�Ƿ��˳���");
				dialog.setIcon(R.drawable.ic_launcher);
				dialog.setCancelable(false);
				dialog.setPositiveButton("�˳�", new DialogInterface.OnClickListener() {
					public void onClick(DialogInterface dialog, int which) {
						mGameStatus = STATUS_DEAD;
						android.os.Process.killProcess(android.os.Process.myPid());
						System.exit(0);
					}
				});
				dialog.setNegativeButton("ȡ��", new DialogInterface.
				OnClickListener() {
					public void onClick(DialogInterface dialog, int which) {
						if (mGameStatus==STATUS_RUN) {
							taskStart(startSpeed);
						}
					}
				});
				dialog.show();
	}
	
	/**
	 * �������ö�ʱ���Լ���ʱ������ķ���
	 * @param peroidÿ��ˢ�µ�ʱ��������λms
	 */
	private void taskStart(long peroid){
		mTimer = new Timer();
		mTimerTask = new TimerTask() {
			@Override
			public void run() {
				// TODO �Զ����ɵķ������
				Message msg = new Message();
				msg.what = SNAKE_MOVE;
				mHandler.sendMessage(msg);
			}
		};
		mTimer.schedule(mTimerTask,peroid,peroid);
	}
	
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
}
