package tech.itunz.data_generator;

import tech.itunz.jni.Jni;

/**
 * Meant for testing: To be later moved into unittests
 */
public class HelloJni {
    public static void main(String[] args) {
        Jni mainObj = new Jni();
        String result = mainObj.generate("x*cos(x)", -200, 400, 1);
        System.out.println(result);
    }
}
