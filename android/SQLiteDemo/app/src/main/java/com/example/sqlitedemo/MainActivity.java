package com.example.sqlitedemo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

    DatabaseHelper helper;
    private EditText e1,e2,e3,e4;
    private Button b1,b2,b3;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        helper = new DatabaseHelper(MainActivity.this);
        e1 = findViewById(R.id.nameField);
        e2 = findViewById(R.id.ageField);
        e3 = findViewById(R.id.marksField);
        e4 = findViewById(R.id.updateField);

        b1 = findViewById(R.id.adder);
        b2 = findViewById(R.id.updater);
        b3 = findViewById(R.id.del);

        b1.setVisibility(View.GONE);
        b2.setVisibility(View.GONE);
        b3.setVisibility(View.GONE);

        e1.setVisibility(View.GONE);
        e2.setVisibility(View.GONE);
        e3.setVisibility(View.GONE);
        e4.setVisibility(View.GONE);

    }

    public void show(View view)
    {
        switch (view.getId())
        {
            case R.id.ShowAdd:  e1.setVisibility(View.VISIBLE);
                                e2.setVisibility(View.VISIBLE);
                                e3.setVisibility(View.VISIBLE);
                                b1.setVisibility(View.VISIBLE);
                                break;
            case R.id.ShowUpdate: e1.setVisibility(View.VISIBLE);
                                  e2.setVisibility(View.VISIBLE);
                                  e3.setVisibility(View.VISIBLE);
                                  e4.setVisibility(View.VISIBLE);
                                  b2.setVisibility(View.VISIBLE);
                                  break;
            case R.id.ShowDelete: e4.setVisibility(View.VISIBLE);
                                    b3.setVisibility(View.VISIBLE);
                                    break;
        }
    }

    public void add(View view)
    {
        String name, ageS, marksS, idS;
        try
        {
            name = e1.getText().toString();
            e1.setText(null);
        }
        catch (NumberFormatException e)
        {
            name = "";
        }
        try
        {
            ageS = e2.getText().toString();
            e2.setText(null);
        }
        catch (NumberFormatException e)
        {
            ageS = "-1";
        }
        try
        {
            marksS = e3.getText().toString();
            e3.setText(null);
        }
        catch (NumberFormatException e)
        {
            marksS = "-1";
        }

        try
        {
            idS = e4.getText().toString();
            e4.setText(null);
        }
        catch (NumberFormatException e)
        {
            idS = "-1";
        }



        if(view.getId() == R.id.updater)
        {
            helper.updateData(name ,  Integer.parseInt(ageS) , Integer.parseInt(marksS), Integer.parseInt(idS));
            hide();
            return;
        }

        else if(view.getId() == R.id.del)
        {
            helper.deleteData(Integer.parseInt(idS));
            hide();
            return;
        }

        helper.addData(name , Integer.parseInt(ageS) , Integer.parseInt(marksS));

        hide();
    }

    public void hide()
    {
        b1.setVisibility(View.GONE);
        b2.setVisibility(View.GONE);
        b3.setVisibility(View.GONE);

        e1.setVisibility(View.GONE);
        e2.setVisibility(View.GONE);
        e3.setVisibility(View.GONE);
        e4.setVisibility(View.GONE);
    }

}
