package com.example.doctus.funnyfights_0001;

import android.app.Activity;
import android.content.Context;
import android.content.pm.ActivityInfo;
import android.os.Bundle;
import android.view.Display;
import android.view.WindowManager;

/**
 * Created by Vania on 31.12.2015.
 */
public class GameActivity extends Activity {

    GameGLSurfaceView mSurfaceView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_USER_LANDSCAPE);
        mSurfaceView = new GameGLSurfaceView(this);
        setContentView(mSurfaceView);
        Display display = ((WindowManager) getSystemService(Context.WINDOW_SERVICE)).getDefaultDisplay();

        float width = display.getWidth();
        float height = display.getHeight();
//        ScreenOptions screenOptions = new ScreenOptions(this);
//        screenOptions.setHeightToWidth(height / width);
    }
}
