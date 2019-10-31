package com.example.sqlitedemo;

import android.content.ContentValues;
import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import androidx.annotation.Nullable;

public class DatabaseHelper extends SQLiteOpenHelper {

    public DatabaseHelper(@Nullable Context context) {
        super(context , "database.db" , null , 1);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {

        db.execSQL("CREATE TABLE STUDENTS (ID INTEGER PRIMARY KEY AUTOINCREMENT , " +
                "NAME VARCHAR, AGE INTEGER, MARKS INTEGER)");

    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int i, int i1) {

        db.execSQL("DROP TABLE IF EXISTS STUDENTS");

        onCreate(db);

    }

    public void addData(String name, int age, int marks)
    {
        SQLiteDatabase data = this.getWritableDatabase();

        ContentValues values = new ContentValues();

        values.put("NAME" , name);
        values.put("AGE" , age);
        values.put("MARKS" , marks);

        data.insert("STUDENTS",null , values);

        data.close();

    }

    public void updateData(String name, int age, int marks, int id)
    {
        SQLiteDatabase data = this.getWritableDatabase();

        ContentValues values = new ContentValues();

        values.put("NAME" , name);
        values.put("AGE" , age);
        values.put("MARKS" , marks);

        data.update("STUDENTS" , values, "ID=?" , new String[]{String.valueOf(id)});

        data.close();

    }

    public void deleteData(int id)
    {
        SQLiteDatabase data = this.getWritableDatabase();

        data.delete("STUDENTS" , "ID=?" , new String[]{String.valueOf(id)});

        data.close();

    }

}
