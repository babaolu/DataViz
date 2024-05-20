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

    /**
     * Handler for the URI - gen_data in form of a post request. It receives the
     * form data containing the formula string to evaluate and other information
     * to determine the number of values to generate
     * @param data FormulaData containing the needed information
     * @return Jsonified string of array of input-output pairs
     */
    @CrossOrigin(methods = {RequestMethod.POST, RequestMethod.HEAD, RequestMethod.OPTIONS}, originPatterns = "*")
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
 
    /**
     * Test function to check that the program is running as expected
     * @return Jsonified string of array of input-output pairs
     */
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
