package com.gmail.fabhin7.lab5_6;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.media.AudioManager;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.ListView;
import android.widget.SeekBar;
import android.widget.TextView;
import android.widget.Toast;

import java.lang.reflect.Field;
import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    ImageButton reset, playPause;
    Button volUp, volDown;
    SeekBar seekBar;
    MediaPlayer mediaPlayer;
    ListView listView;
    TextView tv;
    int duration;
    int maxVolume;
    int currVolume;
    int step;
    private ArrayList<String> songList = new ArrayList<>();
    private ArrayList<Integer> songID = new ArrayList<>();
    AudioManager am;
    Toast t;
    int currID;
    Boolean paused = false;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        am = (AudioManager) getSystemService(Context.AUDIO_SERVICE);
        maxVolume = am.getStreamMaxVolume(AudioManager.STREAM_MUSIC);
        currVolume = am.getStreamVolume(AudioManager.STREAM_MUSIC);
        step = maxVolume/20;

        setListeners();
        updateArrayList();
        updateListView();
        setupSeekBar();
    }

    public void updateListView(){

        ArrayAdapter<String> adapter = new ArrayAdapter<>(this, android.R.layout.simple_list_item_1, songList);
        listView.setAdapter(adapter);
        listView.setOnItemClickListener((adapterView, view, i, l) -> {
            updateMediaPlayer(songID.get(i));
            tv.setText(songList.get(i));
            updateIcon();
        });
    }

    public void updateIcon(){
        if (mediaPlayer == null) return;
        if (mediaPlayer.isPlaying()){
            playPause.setImageResource(android.R.drawable.ic_media_pause);
        }
        else{
            playPause.setImageResource(android.R.drawable.ic_media_play);
        }
    }

    public void setListeners(){
        reset = findViewById(R.id.reset);
        playPause = findViewById(R.id.playPause);
        volUp = findViewById(R.id.volUp);
        volDown = findViewById(R.id.volDown);
        seekBar = findViewById(R.id.seek);
        listView = findViewById(R.id.listView);
        tv = findViewById(R.id.textView);

        playPause.setOnClickListener(v ->{
            if (mediaPlayer == null)
                return;
            if(mediaPlayer.isPlaying())
                mediaPlayer.pause();
            else
                mediaPlayer.start();
            updateIcon();
        });
        volUp.setOnClickListener(v ->{
            if(currVolume == maxVolume)
                return;
            currVolume += step;
            updateVolume();
        });
        volDown.setOnClickListener(v ->{
            if(currVolume == 0)
                return;
            currVolume -= step;
            updateVolume();
        });
        reset.setOnClickListener(v ->{
            mediaPlayer.reset();
            paused = true;
            updateIcon();
        });
    }
    public void updateArrayList(){
        Field[] fields=R.raw.class.getDeclaredFields();
        for (Field field : fields) {
            songList.add(formatName(field.getName()));
            try {
                songID.add(field.getInt(field));
            } catch (IllegalAccessException e) {
                e.printStackTrace();
            }
        }
    }

    public String formatName(String s){
        String temp = s.replaceAll("_", " ").toUpperCase();
        Log.i("Song name", temp);
        return temp;
    }

    public void updateVolume(){
        am.setStreamVolume(AudioManager.STREAM_MUSIC, currVolume,0);

        if (t != null) {
            t.cancel();
        }
        t = Toast.makeText(this,"Volume changed : "+currVolume+"", Toast.LENGTH_SHORT);
        t.show();
    }

    public void updateMediaPlayer(int resID){
        if(currID == resID)
            return;
        currID = resID;
        if (mediaPlayer != null)
            mediaPlayer.reset();
        mediaPlayer = MediaPlayer.create(this,resID);
        duration = mediaPlayer.getDuration();
        mediaPlayer.setAudioStreamType(AudioManager.STREAM_MUSIC);
        mediaPlayer.start();
        setupSeekBar();

    }

    public void setupSeekBar(){
        seekBar.setMax(duration/1000);
        Handler mHandler = new Handler();
            //Make sure you update Seekbar on UI thread
            MainActivity.this.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                if(mediaPlayer != null){
                    int mCurrentPosition = mediaPlayer.getCurrentPosition() / 1000;
                    seekBar.setProgress(mCurrentPosition);
                }
                mHandler.postDelayed(this, 1000);
            }
        });

        seekBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {}

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {}

            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                if(mediaPlayer != null && fromUser){
                    mediaPlayer.seekTo(progress * 1000);
                }
            }
        });
    }
}