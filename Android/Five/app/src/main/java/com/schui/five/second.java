package com.schui.five;

import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.os.Looper;
import android.os.Message;
import android.os.Handler;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.view.Window;
import android.widget.Button;
import android.widget.TextView;

import java.util.Calendar;
import java.util.Timer;
import java.util.TimerTask;
import java.util.logging.ConsoleHandler;
import java.util.logging.LogRecord;

import static android.R.id.message;
import static android.R.id.primary;
import static com.schui.five.R.layout.topten;

public class second extends AppCompatActivity{
    private String[] Num = {"1","2","3","4","5"};

    private com.schui.five.MyView hh;
    private TextView time;
    private TextView Ftime;
    private Button start;
    private Button TopTen;
    private boolean flag;
    private boolean Gflag = true;
    private Timer mTimer = null;
    private TimerTask mtimerTask = null;
    private Handler mHandler = null;
    private SDSql Gsql;
    private String Sname;

    private final int GameStatu = 1;
    private int grade = 0;
    private void taskStart() {
        mTimer = new Timer();
        mtimerTask = new TimerTask() {
            @Override
            public void run() {
                Message msg = new Message();
                msg.what = GameStatu;
                mHandler.sendMessage(msg);
            }
        };

        mTimer.schedule(mtimerTask, 1000, 1000);

    }
    private void showgrade(){    //弹出成绩框
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        String[] Grade = {"最终成绩:"+grade};
        builder.setSingleChoiceItems(Grade, 0, new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialogInterface, int i) {
                dialogInterface.dismiss();
            }
        });
        builder.show();
    }


    private void shownumber(){   //显示输入
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setSingleChoiceItems(Num, 0, new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialogInterface, int i) {
                Gflag = hh.change(Num[i]);
                hh.invalidate();
                dialogInterface.dismiss();
            }
        });
        builder.show();
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        setContentView(R.layout.game);

        hh = (MyView) findViewById(R.id.myview);
        time = (TextView) findViewById(R.id.textView3);
        Ftime = (TextView) findViewById(R.id.textView4);
        start = (Button) findViewById(R.id.button4);
        TopTen = (Button) findViewById(R.id.button3);
        flag = false;

        Bundle bundleIn = getIntent().getExtras();

        Sname = bundleIn.getString("Sname");

        mHandler = new Handler() {
            public void handleMessage(Message msg){
                switch (msg.what){
                    case GameStatu:
                        if(!Gflag){  //游戏结束
                            mTimer.cancel();
                            start.setText("开始");
                            showgrade();//弹出成绩
                            Gsql = new SDSql(second.this);
                            String sql = "INSERT INTO person(name,passwd,grade)" +
                                    " values('"+Sname+"',"+grade+")";
                            Gsql.insertData(sql);
                        }else
                        if (flag){
                            grade++;    //时间加1
                            time.setText("时间:"+grade);
                        }break;
                    default:
                        break;
                }

            }
        };




        hh.setOnClickListener(new View.OnClickListener() {    //点击触发输入
            @Override
            public void onClick(View v) {
                shownumber();
            }
        });

        start.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (!flag){
                    flag = true;
                    start.setText("暂停");
                    hh.invalidate();
                    if (!Gflag){
                        hh.game.InitGame();
                    }
                    taskStart();
                }else{
                    flag = false;
                    start.setText("开始");
                    mTimer.cancel();
                }
                hh.flag = flag;
            }
        });

        TopTen.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intentIn = new Intent();
                intentIn.setClass(second.this,Topten.class);
                startActivity(intentIn);
            }
        });

    }

}
