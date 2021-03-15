package com.gmail.fabhin7.lab2;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import java.util.Arrays;

public class MainActivity2 extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        EditText plainText = findViewById(R.id.plain_text);
        Button button = findViewById(R.id.button);
        TextView cipherText = findViewById(R.id.cipher_text);

        button.setOnClickListener(v -> {
            String text = String.valueOf(plainText.getText());
            char[] array = text.toCharArray();
            for (int i=0;i< array.length;i++){
                array[i]+= 1;
                if(array[i]>'z') array[i] -= 26;
            }
            cipherText.setText(String.valueOf(array));
        });
    }





    // Menu Bar (DO NOT WRITE IN MANUAL)
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.mymenu, menu);
        return super.onCreateOptionsMenu(menu);
    }

    // handle button activities
    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        int id = item.getItemId();

        if (id == R.id.mybutton) {
            startActivity(new Intent(MainActivity2.this, MainActivity3.class));
        }
        return super.onOptionsItemSelected(item);
    }
}