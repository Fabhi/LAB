package com.gmail.fabhin7.lab1;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.TableLayout;
import android.widget.TableRow;
import android.widget.TextView;
import android.widget.Toast;

import java.io.Console;

public class ActivityAdditional extends AppCompatActivity {
    String[][] data = {
            {" ", "M", "T", "W", "T",  "F"},
            {"Day High", "34°C", "35°C", "34°C", "35°C", "33°C"},
            {"Day Low", "28°C", "27°C", "29°C", "26°C", "29°C"},
            {"Conditions"}};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_additional);
        addRows();
        for(int i=0; i<4; i++) updateRow(i, data[i]);
    }

    public void addRows(){
        TableLayout table = findViewById(R.id.table);
        for(int i=100; i<104;i++){
            TableRow row = new TableRow(this);
            row.setId(i);
            row.setLayoutParams(new TableRow.LayoutParams(TableRow.LayoutParams.MATCH_PARENT, TableRow.LayoutParams.WRAP_CONTENT));
            table.addView(row);
        }
    }

    public void updateRow(int index, String[] array){
        TableRow row = findViewById(100+index);
        for (String o : array) {
            TextView tv = (TextView) getLayoutInflater().inflate(R.layout.text_cell, null);
            tv.setText(o);
            row.addView(tv);
        }
        if(index==3){
            for(int i=0;i<5;i++){
                ImageView iv = (ImageView) getLayoutInflater().inflate(R.layout.image_cell, null);
                iv.setImageResource(android.R.drawable.btn_star_big_on);
                row.addView(iv);
            }
        }
    }


}