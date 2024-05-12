#include "tech_itunz_jni_Jni.h"
#include "ProcessComp.h"

JNIEXPORT jdouble JNICALL
Java_tech_itunz_jni_Jni_evaluate(JNIEnv *env, jobject obj, jstring form)
{
    const char *pformChar = env->GetStringUTFChars(form, NULL);
    std::vector<Token> tokenVec;
    unsigned int count = 0;
    double num;
    jclass exceptionClass = env->FindClass("java/lang/IllegalArgumentException");
    /*for (const char *p = pformChar; *p != 0; p++)
      std::cin.putback(*p);*/
    std::string instr{pformChar};
    instr += ";";
    std::istringstream istr{instr};
    try
    {
      takeIn(tokenVec, istr);
      num = add_sub(tokenVec, count);
    }
    catch(BadExpression& e)
    {
      if (exceptionClass != nullptr)
      env->ThrowNew(exceptionClass, "Bad Expression!");
    }
      return (jdouble) num;
}