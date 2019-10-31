package com.example.p12;

import androidx.appcompat.app.AppCompatActivity;

import android.content.ContentValues;
import android.content.Intent;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class Main2Activity extends AppCompatActivity {

    Button b;
    String s,x1,y1,z1;
    EditText x,y,z;
    SQLiteOpenHelper oh;
    SQLiteDatabase db;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        b=findViewById(R.id.b1);
        s=getIntent().getStringExtra("Value");
        x=findViewById(R.id.id);
        y=findViewById(R.id.name);
        z=findViewById(R.id.con );
        oh=new DB(this);
    }

    public void onClick(View view)
    {
       // x1=x.getText().toString();
        y1=y.getText().toString();
        z1=z.getText().toString();

        if(s.equalsIgnoreCase("ADD"))
        {
            db=oh.getWritableDatabase();
            ContentValues cv=new ContentValues();
            cv.put(DB.col2, y1);
            cv.put(DB.col3, z1);
            long id=db.insert(DB.tName, null,cv);
            s="Insertion successful";
        }
        else if(s.equalsIgnoreCase("DEL"))
        {

        }
        else
        {

        }
        Toast.makeText(getApplicationContext(),s,Toast.LENGTH_LONG).show();

        Intent i=new Intent(getApplicationContext(),MainActivity.class);
        startActivity(i);
    }
}

