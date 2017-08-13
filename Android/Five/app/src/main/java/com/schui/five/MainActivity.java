package com.schui.five;

import android.content.Intent;
import android.nfc.Tag;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import static android.R.id.button1;
import static android.icu.lang.UCharacter.GraphemeClusterBreak.L;


public class MainActivity extends AppCompatActivity {

    private EditText name;
    private EditText passwd;
    private Button login;
    private Button signup;
    private String Sname;
    private String Spasswd;
    private SDSql Gsql;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
       setContentView(R.layout.activity_main);

       // SDSql.beginCopyDB(this,"shudu.db","/data/data/com.schui.five/databases/",true);


        name = (EditText) findViewById(R.id.editText);
        passwd = (EditText) findViewById(R.id.editText2);
        login = (Button) findViewById(R.id.button);
        signup = (Button) findViewById(R.id.button2);

        Sname = name.getText().toString();
        Spasswd = passwd.getText().toString();
        //登录
        login.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Gsql = new SDSql(MainActivity.this);
               String sql = "SELECT rowid _id,* FROM person where name = '"+Sname+"'";
                Gsql.selectData(sql);
             if (Gsql.p.passd.equals(Spasswd))
                {
                    Bundle bundleIn = new Bundle();
                    bundleIn.putString("Sname",Sname);

                    Intent intentIn = new Intent();
                    //跳转到游戏页面
                    intentIn.setClass(MainActivity.this,second.class);
                    intentIn.putExtras(bundleIn);
                    startActivity(intentIn);
                }
               else {
                 login.setText("请注册");
             }

            }
        });

        signup.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Gsql = new SDSql(MainActivity.this);
               String sql = "INSERT INTO person (name,passwd,grade)" +
                        " values('"+Sname+"','"+Spasswd+"',100)";
                Gsql.insertData(sql);
                signup.setText("ok");
            }
        });

        }
}
