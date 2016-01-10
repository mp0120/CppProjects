package com.example.doctus.funnyfights_0001.Constants;

/**
 * Created by doctus on 10.01.16.
 */
public class Constants {

    public static final int COORDS_PER_VERTEX = 3;

    public static final String VERTEX_SHADER_CODE =
            "attribute vec4 vPosition;" +
            "void main() {" +
            "  gl_Position = vPosition;" +
            "}";

    public static final String FRAGMENT_SHADER_CODE =
            "precision mediump float;" +
                    "uniform vec4 vColor;" +
                    "void main() {" +
                    "  gl_FragColor = vColor;" +
                    "}";
}
