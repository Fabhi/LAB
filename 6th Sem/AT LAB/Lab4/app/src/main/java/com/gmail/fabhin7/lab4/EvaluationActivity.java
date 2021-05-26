package com.gmail.fabhin7.lab4;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.Spinner;

import java.util.ArrayList;

public class EvaluationActivity extends AppCompatActivity {
    ArrayList<String> element = new ArrayList<String>();
    ArrayAdapter<String> aa;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_evaluation);
        element.add("i1");
        element.add("i2");
        Spinner spin = findViewById(R.id.element_spinner);

        EditText editText = findViewById(R.id.element_edit);
        ImageButton addButton = findViewById(R.id.add_button),
                minusButton = findViewById(R.id.minus_button);

        addButton.setOnClickListener(v->{
            String text = editText.getText().toString();
            if(text.equals(""))
                return;
            aa.add(text);
            aa.notifyDataSetChanged();
        });
        minusButton.setOnClickListener(v->{
            String text = editText.getText().toString();
            if(text.equals(""))
                return;
            aa.remove(text);
            aa.notifyDataSetChanged();
        });

        //Creating the ArrayAdapter instance having the country list
        aa = new ArrayAdapter<>(this, android.R.layout.simple_spinner_item, element);
        aa.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        spin.setAdapter(aa);
    }
}