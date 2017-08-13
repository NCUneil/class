package com.example.aaa.a2048;

import android.content.SharedPreferences;
import android.widget.Button;
import android.widget.TextView;

import org.w3c.dom.Text;

import java.util.Random;

/**
 * Created by 李明坡 on 2016/12/28.
 */

public class Maps {
    private TextView score,best;
    private Button[][] maps=new Button[4][5];
    //初始化界面
    public void init()
    {
        for(int i=0;i<4;++i)
        {
            for(int j=0;j<5;++j)
            {
                maps[i][j].setText("");
            }
        }
        score.setText("0");
        addNumbers();
        addNumbers();
    }
    private void addNumbers()
    {
        Random random = new Random();
        int x = random.nextInt(4);
        int y = random.nextInt(5);
        int number = random.nextInt(20);
        if (number==0)
        {
            number=4;
        }
        else
        {
            number=2;
        }
        while(maps[x][y].getText().toString().length()!=0)
        {
            x=random.nextInt(4);
            y=random.nextInt(5);
        }
        maps[x][y].setText(number+"");
    }
    private  boolean isFull()
    {
        for(int i=0;i<4;++i)
        {
            for(int j=0;j<5;++j)
            {
                if(maps[i][j].getText().toString().length()==0)
                {
                    return false;
                }
            }
        }
        return true;
    }
    public boolean Slide(int direction)
    {
        if(direction==Direction.LEFT)
        {
            left_remove_blank();
            left();
            if(isFull())
            {
                return true;
            }
            else
            {
                addNumbers();
            }
        }
        if(direction==Direction.RIGHT)
        {
            right_remove_blank();
            right();
            if(isFull())
            {
                return true;
            }
            else
            {
                addNumbers();
            }
        }
        if(direction==Direction.UP)
        {
             up_remove_blank();
             up();
            if(isFull())
            {
                return true;
            }
            else
            {
                addNumbers();
            }
        }
        if(direction==Direction.DOWN)
        {
            down_remove_blank();
            down();
            if(isFull())
            {
                return true;
            }
            else
            {
                addNumbers();
            }
        }
        return false;
    }

    void up()
    {
        int i,j;
        for(j=0;j<5;++j)
        {
            for(i=0;i<3;++i)
            {
                String s1=maps[i][j].getText().toString();
                String s2=maps[i+1][j].getText().toString();
                if(s1.equals(s2)&&!s1.equals(""))
                {
                    Integer sum=Integer.valueOf(maps[i][j].getText().toString());
                    sum+=Integer.valueOf(maps[i+1][j].getText().toString());
                    int total=Integer.valueOf(score.getText().toString());
                    score.setText(String.valueOf(sum+total));
                    maps[i][j].setText(sum.toString());
                    maps[i+1][j].setText("");
                    up_remove_blank();
                }
            }
        }
    }
    private void down()
    {
        int i,j;
        for(j=0;j<5;++j)
        {
            for(i=3;i>=1;--i)
            {
                String s1=maps[i][j].getText().toString();
                String s2=maps[i-1][j].getText().toString();
                if(s1.equals(s2)&&!s1.equals(""))
                {
                    Integer sum=Integer.valueOf(maps[i][j].getText().toString());
                    sum+=Integer.valueOf(maps[i-1][j].getText().toString());
                    int total=Integer.valueOf(score.getText().toString());
                    score.setText(String.valueOf(sum+total));
                    maps[i][j].setText(sum.toString());
                    maps[i-1][j].setText("");
                    down_remove_blank();
                }
            }
        }
    }
    private void left()
    {
        int i,j;
        for(i=0;i<4;++i)
        {
            for(j=0;j<4;++j)
            {
                String s1=maps[i][j].getText().toString();
                String s2=maps[i][j+1].getText().toString();
                if(s1.equals(s2)&&!s1.equals(""))
                {
                    Integer sum=Integer.valueOf(s1);
                    sum+=Integer.valueOf(s2);
                    Integer total=Integer.valueOf(score.getText().toString());
                    score.setText(String.valueOf(sum+total));
                    maps[i][j].setText(sum.toString());
                    maps[i][j+1].setText("");
                    left_remove_blank();
                }
            }
        }
    }
    private void right()
    {
        int i,j;
        for(i=0;i<4;++i)
        {
            for(j=4;j>=1;--j)
            {
                String s1=maps[i][j].getText().toString();
                String s2=maps[i][j-1].getText().toString();
                if(s1.equals(s2)&&!s1.equals(""))
                {
                    Integer sum=Integer.valueOf(maps[i][j].getText().toString());
                    sum+=Integer.valueOf(maps[i][j-1].getText().toString());
                    int total=Integer.valueOf(score.getText().toString());
                    score.setText(String.valueOf(sum+total));
                    maps[i][j].setText(sum.toString());
                    maps[i][j-1].setText("");
                    right_remove_blank();
                }
            }
        }
    }
    private void up_remove_blank()
    {
        int i,j,k;
        for(j=0;j<5;++j)
        {
            for(i=1;i<4;++i)
            {
                k=i;
                while(k-1>=0&&maps[k-1][j].getText().toString().length()==0)
                {
                    swapText(maps[k][j],maps[k-1][j]);
                    k--;
                }
            }
        }
    }
    private void down_remove_blank()
    {
        int i,j,k;
        for(j=0;j<5;++j)
        {
            for(i=2;i>=0;--i)
            {
                k=i;
                while(k+1<=3 && maps[k+1][j].getText().toString().length()==0)
                {
                    swapText(maps[k][j],maps[k+1][j]);
                    k++;
                }
            }
        }
    }
    private void left_remove_blank()
    {
        int i,j,k;
        for(i=0;i<4;++i)
        {
            for(j=1;j<5;++j)
            {
                k=j;
                while(k-1>=0&&maps[i][k-1].getText().toString().length()==0)
                {
                    swapText(maps[i][k],maps[i][k-1]);
                    k--;
                }
            }
        }
    }
    private void right_remove_blank()
    {
        int i,j,k;
        for(i=0;i<4;++i)
        {
            for(j=3;j>=0;--j)
            {
                k=j;
                while(k+1<=4 && maps[i][k+1].getText().toString().length()==0)
                {
                    swapText(maps[i][k],maps[i][k+1]);
                    k++;
                }
            }
        }
    }
    private void swapText(Button bt1,Button bt2)
    {
        CharSequence text=bt1.getText();
        bt1.setText(bt2.getText());
        bt2.setText(text);
    }
    public void addButton(int i,int j,Button btn)
    {
        maps[i][j]=btn;
    }
    public void setScore(TextView score)
    {
        this.score=score;
    }
    public void setBest(TextView best)
    {
        this.best=best;
        best.setText(getBestScore()+"");
    }
    public int getScore()
    {
        return Integer.valueOf(score.getText().toString());
    }
    public int getBestScore()
    {
        SharedPreferences sp=best.getContext().getSharedPreferences("bestScore",0);
        int bestScore=sp.getInt("bestScore",0);
        return bestScore;
    }
    public void setBestScore(int score)
    {
        SharedPreferences sp=best.getContext().getSharedPreferences("besrScore",0);
        SharedPreferences.Editor edit=sp.edit();
        edit.putInt("bestScore",score);
        edit.commit();
    }

}
