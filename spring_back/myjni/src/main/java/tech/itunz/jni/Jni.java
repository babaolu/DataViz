/*
 * This Java source file was generated by the Gradle 'init' task.
 */
package tech.itunz.jni;

import java.util.ArrayList;
import java.util.HashMap;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.core.JsonProcessingException;

public class Jni {

    ArrayList<HashMap<String, Double>> maplist;
    public native double evaluate(String form);

    static {
        System.loadLibrary("calc");
    }

    public String generate(String formula, double stPoint, double smpSize, double interv) {
        maplist = new ArrayList<HashMap<String, Double>>();
        String result = "";
        for (double i = 0; i <= smpSize; i++)
        {
            double effectiveVal = stPoint + (i * interv);
            String eval = formula.replace("x", String.valueOf(effectiveVal));
            eval = eval.replace("Pi", String.valueOf(Math.PI));
            eval = eval.replace("e", String.valueOf(Math.exp(1)));
            HashMap<String, Double> point = new HashMap<String, Double>();
            point.put("x", Double.valueOf(effectiveVal));
            point.put("y", evaluate(eval));
            maplist.add(point);
        }
        try {
            result = new ObjectMapper().writeValueAsString(maplist);
        } catch (JsonProcessingException ex)
        {
            System.out.println("Could not process JSON: " + ex.getMessage());
            ex.printStackTrace();
        }
        return result;
    }

    public static void main(String[] args) {
        Jni mainObj = new Jni();
        String result = mainObj.generate("x*x-2*x+1", -200, 400, 1);
        System.out.println(result);
    }
}
