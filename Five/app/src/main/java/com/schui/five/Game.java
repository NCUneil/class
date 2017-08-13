package com.schui.five;

import org.jetbrains.annotations.Contract;

import java.util.ArrayList;
import java.util.Random;

import static android.R.attr.x;
import static android.R.attr.y;


public class Game {

    private int[] shuduku = {4,3,1,2,5,2,1,4,5,3,5,4,3,1,2,3,5,2,4,1,1,2,5,3,4};

    private int[] init = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    public static ArrayList<Integer> creatNineRondomArray()
    {
        ArrayList <Integer>list = new ArrayList<Integer>();
        Random random=new Random();
        for (int i = 0; i < 5; i++) {
            int randomNum=random.nextInt(5)+1;
            while (true) {
                if (!list.contains(randomNum)) {
                    list.add(randomNum);
                    break;
                }
                randomNum=random.nextInt(5)+1;
            }

        }
        return list;
    }


    public static void creatSudokuArray(int[]shuduku,ArrayList<Integer> randomList) {
        int flag = 1;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    if (shuduku[i * 5 + j] == randomList.get(k)) {
                        shuduku[i * 5 + j] = randomList.get((k + 1) % 5);
                        break;
                    }
                }
            }
        }
    }



    public boolean check()

            //检查游戏是否重复
    {
        int row;int col;int tmp;
        for (row = 0;row < 5;row++){
        int num[] = {0,0,0,0,0,0};
        for (col = 0;col < 5;col++){
            tmp = shuduku[row*5+col];
            if (num[tmp] == 1&&tmp==0){
                return true;
            }else
            {
                num[tmp] = 1;
            }
        }
    }
        //列是否重复
        for (row = 0;row < 5;row++){
            int num[] = {0,0,0,0,0,0};
            for (col = 0;col < 5;col++){
                tmp = shuduku[col*5+row];
                if (num[tmp] == 1&&tmp == 0){
                    return true;
                }else
                {
                    num[tmp] = 1;
                }
            }
        }

        return false;
    }

    public Game()
    {
        InitGame();
    }

   public void InitGame() //初始化页面
    {
        ArrayList<Integer> randomList=Game.creatNineRondomArray();
        Game.creatSudokuArray(shuduku, randomList);

        Random rand = new Random();

        for (int i = 0;i < 2;i++)
        {
            init[rand.nextInt(5)] = 1;
            init[5+rand.nextInt(5)] = 1;
            init[10+rand.nextInt(5)] = 1;
            init[15+rand.nextInt(5)] = 1;
            init[20+rand.nextInt(5)] = 1;
        }
        for (int i = 0;i < 25;i++)
        {
            if (init[i] == 0)
            {
                shuduku[i] = 0;
            }
        }
    }

    public boolean change(String s,int x,int y)
    {
        if (init[x*5+y] == 0) {
            shuduku[x * 5 + y] = s.charAt(0) - '0';
        }
        return  check();
    }

    private int getTile(int x , int y)
    {
        return shuduku[x*5+y] ;
    }

    public int getkey(int x,int y)
    {
        return init[x*5+y];
    }

    public String getTileString(int x , int y)
    {
        int v = getTile(x , y);
        if(0 == v)
            return "" ;
        else
            return String.valueOf(v); //把获取的 整数 转成 字符串
    }

}
