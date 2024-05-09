package tech.itunz.data_generator;

import tech.itunz.jni.Jni;

public class HelloJni {
    public static void main(String[] args) {
        Jni mainObj = new Jni();
        String result = mainObj.generate("x*x-2*x+1", -200, 400, 1);
        System.out.println(result);
    }
}
