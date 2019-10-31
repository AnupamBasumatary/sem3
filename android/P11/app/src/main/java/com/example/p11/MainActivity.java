package com.example.p11;

import android.app.Dialog;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

    }

    public void login(View view)
    {
        EditText e1 = findViewById(R.id.username);

        String user = e1.getText().toString();

        e1 =findViewById(R.id.password);

        String pass = e1.getText().toString();

        if(user.equals("admin") && pass.equals("admin"))
        {
            Intent i1 = new Intent(this , Logout.class);

            i1.putExtra(Intent.EXTRA_TEXT , user);

            startActivity(i1);

        }


    }

}
