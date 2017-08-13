package com.example.aaa.a2048;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Button;
import android.widget.GridLayout;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    GridLayout gridLayout;
    float startX=0,startY=0,endX,endY;
    Maps maps=new Maps();
    private TextView score;
    private TextView best;

    void init() {
        gridLayout = (GridLayout) findViewById(R.id.root);

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 5; ++j) {
                Button bn = new Button(this);
                bn.setClickable(false);
                bn.setText("");
                bn.setTextSize(30);
                bn.setWidth(120);
                bn.setHeight(120);
                GridLayout.Spec rowSpec = GridLayout.spec(i + 2);
                GridLayout.Spec columnSpec = GridLayout.spec(j);
                String msg = "rowSpec:" + (i + 2) + "- columnSpec:" + (j);
                GridLayout.LayoutParams params = new GridLayout.LayoutParams(rowSpec, columnSpec);
                gridLayout.addView(bn, params);
                maps.addButton(i, j, bn);
            }
        }
        score = (TextView) findViewById(R.id.score);
        score.setText("0");
        best = (TextView) findViewById(R.id.best);
        maps.setScore(score);
        maps.setBest(best);
        maps.init();
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        init();
    }
    @Override
    public  boolean dispatchTouchEvent(MotionEvent event)
    {
        int action=event.getAction();
        if(action==MotionEvent.ACTION_DOWN)
        {
            startX=event.getX();
            startY=event.getY();
        }
        else if(action==MotionEvent.ACTION_UP)
        {
            endX=event.getX();
            endY=event.getY();
            int direction=GetSlideDirection(startX,startY,endX,endY);
            boolean gameOver=maps.Slide(direction);
            if(gameOver)
            {
                if(maps.getScore()>maps.getBestScore())
                {
                    Toast.makeText(this,"恭喜超过最佳纪录！！！",Toast.LENGTH_SHORT).show();
                    maps.setBestScore(maps.getScore());
                    best.setText(maps.getScore()+"");
                }
                else
                {
                    Toast.makeText(this,"GameOver",Toast.LENGTH_SHORT).show();
                }
            }
        }
        return super.dispatchTouchEvent(event);
    }

    //返回角度
    private  double GetSlideAngle(float dx,float dy)
    {
        return Math.atan2(dy,dx)*180/Math.PI;
    }

    private int GetSlideDirection(float startX,float startY,float endX,float endY)
    {
        float dy=startY-endY;
        float dx=startX-endX;
        int result=Direction.NONE;
        if(Math.abs(dx)<2 && Math.abs(dy)<2)
        {
            return  result;
        }
        double angle=GetSlideAngle(dx,dy);
        if(angle>= -45 && angle<45)
        {
            return  Direction.LEFT;
        }else if(angle>=45 && angle<135)
        {
            return Direction.UP;
        }else if(angle>= -135 && angle< -45)
        {
            return Direction.DOWN;
        }
        else if((angle>=135 && angle<=180)||(angle>= -180 && angle< -135))
        {
            return Direction.RIGHT;
        }
        return result;
    }

    public void reset(View view)
    {
        maps.init();
    }
}
