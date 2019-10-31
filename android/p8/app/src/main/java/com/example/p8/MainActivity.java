package com.example.p8;
import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.RelativeLayout;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    Button b1, b2, b3;
    RelativeLayout r1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        b1 = (Button) findViewById(R.id.btn1);
        b2 = (Button) findViewById(R.id.btn2);
        b3 = (Button) findViewById(R.id.btn3);
        r1 = (RelativeLayout) findViewById(R.id.RL);

        b1.setOnClickListener(new View.OnClickListener() {

            public void onClick(View v) {
                r1.setBackgroundColor(Color.RED);
            }
        });

        b2.setOnClickListener(new View.OnClickListener() {

            public void onClick(View v) {
                r1.setBackgroundColor(Color.BLUE);
            }
        });

        b3.setOnClickListener(new View.OnClickListener() {

            public void onClick(View v) {
                r1.setBackgroundColor(Color.GREEN);
            }
        });
    }
}