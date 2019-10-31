package com.example.p12;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import androidx.annotation.Nullable;

public class DB extends SQLiteOpenHelper {
    public static final String dbName="college.db";
    public static final String tName="college";
    public static final String col1="ID";
    public static final String col2="name";
    public static final String col3="contact";


    public DB(@Nullable Context context) {
        super(context, dbName, null, 1);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL("CREATE TABLE "+ tName+ "(ID INTEGER PRIMARY KEY AUTOINCREMENT,name TEXT, contact TEXT)");

    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL("DROP TABLE IF EXISTS "+tName);
        onCreate(db);

    }
}
