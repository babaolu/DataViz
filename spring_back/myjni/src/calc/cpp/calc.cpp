#include "tech_itunz_jni_Jni.h"
#include "ProcessComp.h"

/**
 * Actual implementation of native function using jni.
 * @param env interface to jni environment
 * @param obj reference to the implementing class' object
 * @param form Aritmetic expression to be evaluated
 * @return Evaluated value
*/
JNIEXPORT jdouble JNICALL
Java_tech_itunz_jni_Jni_evaluate(JNIEnv *env, jobject obj, jstring form)
{
    const char *pformChar = env->GetStringUTFChars(form, NULL);
    std::vector<Token> tokenVec;
    unsigned int count = 0;
    double num;
    jclass exceptionClass = env->FindClass("java/lang/IllegalArgumentException");
    std::string instr{pformChar};
    instr += ";";
    std::istringstream istr{instr};
    
    try
    {
      takeIn(tokenVec, istr);  // Tokenizes the string into a vector of Tokens
      num = add_sub(tokenVec, count);  // Expression evaluator
    }
    catch(BadExpression& e)
    {
      if (exceptionClass != nullptr)
      env->ThrowNew(exceptionClass, "Bad Expression!");
    }
      return (jdouble) num;
}