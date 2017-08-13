package com.schui.five;

import android.app.ProgressDialog;
import android.content.Context;
import android.content.res.Resources;
import android.database.Cursor;
import android.database.sqlite.SQLiteException;
import android.database.SQLException;
import android.database.sqlite.SQLiteQueryBuilder;
import android.database.sqlite.SQLiteQuery;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.util.Log;
import android.widget.Toast;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.sql.SQLData;

import static android.R.attr.name;
import static android.content.ContentValues.TAG;
import static javax.xml.transform.OutputKeys.VERSION;

/**
 * Created by 尚朝辉 on 2017/1/2.
 */

public class SDSql{


    /*public static void beginCopyDB(Context context,String dbname,String copyToPath,boolean isReWrite){
        try {
            File file = new File(copyToPath+dbname);

            if (file.exists() == false)
            {
                InputStream isRef = context.getResources().openRawResource(R.raw.shudu);
                FileOutputStream fosRef = new FileOutputStream(file);
                byte[] byteArray = new byte[2];
                int readLength = isRef.read(byteArray);
                while (readLength != -1){
                    fosRef.write(byteArray,0,readLength);
                    readLength = isRef.read(byteArray);
                }
                fosRef.close();
                isRef.close();
            }
            else {
                if (isReWrite == true){
                    if (file.delete() == true){
                        InputStream isRef = context.getResources().openRawResource(R.raw.shudu);
                        FileOutputStream fosRef = new FileOutputStream(file);
                        byte[] byteArray = new byte[2];
                        int readLength = isRef.read(byteArray);
                        while (readLength != -1){
                            fosRef.write(byteArray,0,readLength);
                            readLength = isRef.read(byteArray);
                        }
                        fosRef.close();
                        isRef.close();

                    }
                }
            }
        }catch (Resources.NotFoundException e){
            e.printStackTrace();
        }catch (FileNotFoundException e){
            e.printStackTrace();
        }catch (IOException e){
            e.printStackTrace();
        }
    }
*/
    public class Data{
        String name = null;
        String passd = null;
        int grade = 0;
    }


    public Data p = new Data();
    private final static String DATABASE_NAME = "shudu.db";
    private final static int DB_VERSION = 1;
    //private final static String TABLE_NAME = "";
    private final static String DB_CREATE_TABLE = "create table person(" +
            "name text primary key," +
            "passwd text," +
            "grade integer)";

    public SQLiteDatabase m_SQLiteDatabase = null;
    public DatabaseHelper m_DatabaseHelper = null;

    private static class DatabaseHelper extends SQLiteOpenHelper
    {
      private static DatabaseHelper mInstance = null;
        public DatabaseHelper(Context context) {
          //  java.lang.Process runsu = Runtime.getRuntime().exec("su");
            super(context, DATABASE_NAME, null, DB_VERSION);
            Log.v(TAG,"create db ok!");
        }
      public static synchronized DatabaseHelper getInstance(Context context) {
           if (mInstance == null) {
                mInstance = new DatabaseHelper(context);
           }
            return mInstance;
        }

        @Override
        public void onCreate(SQLiteDatabase db) {
           db.execSQL(DB_CREATE_TABLE);
        }
        @Override
        public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        }
    }
    public SDSql(Context context)
    {
        m_DatabaseHelper = DatabaseHelper.getInstance(context);

        m_SQLiteDatabase = m_DatabaseHelper.getWritableDatabase();
        Log.v(TAG,"dbpath----0-0"+m_SQLiteDatabase.getPath());
    }

    public boolean deleteDatabase(Context context)
    {
        return context.deleteDatabase(DATABASE_NAME);
    }
    public void createTable(String sql)
    {
        m_SQLiteDatabase.execSQL(sql);
    }
    public void deleteTable(String sql)
    {
        m_SQLiteDatabase.execSQL(sql);
    }

    public void insertData(String sql)
    {
        Log.v(TAG, "ok1");
        m_SQLiteDatabase.execSQL(sql);
        Log.v(TAG, "ok2");
    }
    public void deleteData(String sql)
    {
        m_SQLiteDatabase.execSQL(sql);
    }
    public void updateData(String sql)
    {
        m_SQLiteDatabase.execSQL(sql);
    }

    public Cursor selectTopTen(){
        Log.v(TAG,"TOP__TEN");
        return m_SQLiteDatabase.rawQuery("SELECT rowid _id,name,grade FROM person ORDER BY grade DESC LIMIT 10",null);
    }

    public void selectData(String sql)
    {
        Log.v(TAG,"select !");
        Cursor cursor = m_SQLiteDatabase.rawQuery(sql,null);
        Log.v(TAG,"select !");
       // p.grade = cursor.getCount();
        //cursor.moveToFirst();
        while (cursor.moveToNext()) {
            p.name = cursor.getString(cursor.getColumnIndex("name")); //获取第一列的值,第一列的索引从0开始
            Log.v(TAG,p.name);
            p.passd = cursor.getString(cursor.getColumnIndex("passwd"));//获取第二列的值
            Log.v(TAG,p.passd);
            p.grade = cursor.getInt(cursor.getColumnIndex("grade"));//获取第三列的值
        }
        Log.v(TAG,"--------");

        cursor.close();
        m_SQLiteDatabase.close();
    }

}


