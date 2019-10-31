package com.example.p6;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.RadioButton;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    RadioButton a,b,c,d;
    TextView t;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        a=findViewById(R.id.r1);
        b=findViewById(R.id.r2);
        c=findViewById(R.id.r3);
        d=findViewById(R.id.r4);
        t=findViewById(R.id.t1);
    }
    public void Back(View view)
    {
        String s=" ";
        switch(view.getId())
        {
            case R.id.r1:   if(a.isChecked())
                                s="Harmeet Maam";
                            break;
            case R.id.r2:   if(b.isChecked())
                                s="Divya Maam";
                                break;
            case R.id.r3:   if(c.isChecked())
                                s="Manju Maam";
                                break;
            case R.id.r4:   if(d.isChecked())
                                s="S.k sir";
                                break;
        }
        t.setText(s);
    }
}
