package com.example.p12;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;

public class MainActivity extends AppCompatActivity {
    ImageView i,j,k;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
    public void image(View v){
        String s1="";
        i=findViewById(R.id.i1);
        j=findViewById(R.id.i2);
        k=findViewById(R.id.i3);
        switch(v.getId())
        {
            case R.id.i1:   s1="ADD";
                            break;
            case R.id.i2:   s1="DEL";
                            break;
            case R.id.i3:   s1="UPD";
                            break;
        }
        Intent i1 = new Intent(this , Main2Activity.class);
        i1.putExtra("Value",s1);
        startActivity(i1);
    }
}
