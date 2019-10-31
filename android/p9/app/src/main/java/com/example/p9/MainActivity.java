package com.example.p9;

import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;

public class MainActivity extends AppCompatActivity {

    Button b1, b2, b3;
    LinearLayout l;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        l = findViewById(R.id.l1);
    }

    public void Back(View view) {

        switch (view.getId()) {
            case R.id.b1:
                l.setBackgroundColor(Color.RED);
                break;
            case R.id.b2:
                l.setBackgroundColor(Color.GREEN);
                break;
            case R.id.b3:
                l.setBackgroundColor(Color.YELLOW);
                break;
        }
    }
}
