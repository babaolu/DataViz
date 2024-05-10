package tech.itunz.data_generator.controllers;

import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;

import tech.itunz.data_generator.FormulaData;
import tech.itunz.jni.Jni;

@RestController
public class HomeController {

    @CrossOrigin(methods = {RequestMethod.POST, RequestMethod.HEAD, RequestMethod.OPTIONS}, originPatterns = "http://*:3000")
    @ResponseBody
    @PostMapping(path = "gen_pdata")
    public String generate(@RequestBody FormulaData data)
    {
        String formula = data.getFormula_input();
        double stPoint = data.getStart_point();
        double smpSize = data.getSample_size();
        double interv = data.getSample_interval();
        Jni mainObj = new Jni();
        String result = mainObj.generate(formula, stPoint, smpSize, interv);
        return result;
    }
  
    @CrossOrigin
    @ResponseBody
    @GetMapping(path = "gen_data")
    public String gentest()
    {
        Jni mainObj = new Jni();
        String result = mainObj.generate("x*x-2*x+1", -200, 400, 1);
        return result;
    }
}
