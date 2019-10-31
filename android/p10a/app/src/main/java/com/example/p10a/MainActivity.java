package com.example.p10a;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
    public void onClick(View view)
    {
        EditText userName = findViewById(R.id.username);

        String s1 = userName.getText().toString();

        EditText ps=findViewById(R.id.password);

        String s2 = ps.getText().toString();

        if(s1.equals("shivank") && s2.equals("android"))
        {
            Intent i1 = new Intent(this , Main2Activity.class);

            i1.putExtra(Intent.EXTRA_TEXT , s1);

            startActivity(i1);

        }


    }
}
