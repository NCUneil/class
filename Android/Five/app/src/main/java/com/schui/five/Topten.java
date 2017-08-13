package com.schui.five;

import android.app.Activity;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.nfc.Tag;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.Window;
import android.widget.ListView;
import android.widget.SimpleCursorAdapter;
import android.widget.TextView;

import static com.schui.five.R.id.grade;
import static com.schui.five.R.id.num;


public class Topten extends Activity {

    private ListView lisview;//列表
    private SDSql db = null;
    private Cursor cursor = null; //数据库返回
    private SimpleCursorAdapter adapter = null; //listview接口

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        setContentView(R.layout.topten);

        lisview = (ListView) findViewById(R.id.list);
        db = new SDSql(Topten.this);
        cursor = db.selectTopTen();
        //cursor.moveToFirst();
        if (cursor != null) {
            adapter = new SimpleCursorAdapter(this,
                    R.layout.topten, cursor,
                    new String[]{"_id","name","grade"},
                    new int[]{num,R.id.name,R.id.grade}, 0);
            lisview.setAdapter(adapter);
        }

    }


}
