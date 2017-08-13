package com.schui.five;

import android.content.Context;
import android.content.DialogInterface;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.nfc.Tag;
import android.support.v7.app.AlertDialog;
import android.util.AttributeSet;
import android.util.Log;
import android.view.MotionEvent;
import android.view.View;
import android.widget.AdapterView;

import static android.R.attr.y;
import static com.schui.five.R.color.light;
import static com.schui.five.R.color.line;


public class MyView extends View {

    private int Height;
    private int Width;
    private int mOffsetX = 0;
    private int mOffsetY = 0;
    public Game game = new Game();
    private float x;
    private float y;
    public boolean flag = false
            ;

    public MyView(Context context, AttributeSet attrs){
        super(context,attrs);
        this.setFocusable(true);
    }
    public MyView(Context context){
        super(context);
        this.setFocusable(true);
    }

   public boolean onTouchEvent(MotionEvent event){
        if (event.getAction() == MotionEvent.ACTION_DOWN){
            x = event.getX();
            y = event.getY();
        }

        return super.onTouchEvent(event);

    }

    public boolean change(String s)
    {
       int i = (int)(y/Height);
       int j = (int)(x/Width);
       return game.change(s,i,j);
    }



   protected void onSizeChanged(int w, int h, int oldw, int oldh) {

        Height = w / 5;
        Width = h / 5;
       super.onSizeChanged(w, h, oldw, oldh);

    }

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);

        Paint backgroundpaint = new Paint();
        backgroundpaint.setColor(getResources().getColor(
                R.color.game_background));
        canvas.drawRect(0, 0, getWidth(), getHeight(), backgroundpaint);//画背景

        Paint dark = new Paint();
        dark.setColor(getResources().getColor(R.color.dark));

        Paint light = new Paint();
        light.setColor(getResources().getColor(R.color.light));

        Paint line = new Paint();
        line.setColor(getResources().getColor(R.color.line));

        Paint hilite = new Paint();
        hilite.setColor(getResources().getColor(R.color.hilite));

        for (int i = 0; i <= 5; i++) {
            canvas.drawLine(mOffsetX, i * Height, getWidth(), i * Height, dark);
            canvas.drawLine(mOffsetX, i * Height + 1, getWidth(), i * Height + 1, dark);
            canvas.drawLine(i * Width, mOffsetY, i * Width, getWidth(), dark);
            canvas.drawLine(i * Width + 1, mOffsetY, i * Width + 1, getWidth(), dark);
        }

        Paint keyPaint = new Paint();
        keyPaint.setColor(Color.RED);
        keyPaint.setTextSize(30);

        Paint frontPaint = new Paint();
        frontPaint.setColor(Color.BLACK);
        frontPaint.setTextSize(30);
        if (flag) {
            for (int i = 0; i < 5; i++)//x轴
            {
                for (int j = 0; j < 5; j++)//y轴
                {
                    String s = game.getTileString(i, j);
                    if (game.getkey(i, j) == 0) {  //黑
                        canvas.drawText(s, j
                                * Height + (Height * 0.4f), (i + 1) * Width - (Width * 0.4f), frontPaint);
                    } else {
                        canvas.drawText(s, j
                                * Height + (Height * 0.4f), (i + 1) * Width - (Width * 0.4f), keyPaint);
                    }

                }
            }
        }
    }
}
