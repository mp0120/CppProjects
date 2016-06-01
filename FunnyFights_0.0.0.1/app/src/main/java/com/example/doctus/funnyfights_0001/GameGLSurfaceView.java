package com.example.doctus.funnyfights_0001;

import android.content.Context;
import android.opengl.GLSurfaceView;

/**
 * Created by Vania on 31.12.2015.
 */
public class GameGLSurfaceView extends GLSurfaceView {

    GameRenderer mRenderer;

    public GameGLSurfaceView(Context context) {
        super(context);
        // Create an OpenGL ES 2.0 context
        setEGLContextClientVersion(2);

        mRenderer = new GameRenderer();

        // Set the Renderer for drawing on the GLSurfaceView
        setRenderer(mRenderer);
    }
}
