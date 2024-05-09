#include "tech_itunz_jni_Jni.h"
#include "ProcessComp.h"

JNIEXPORT jdouble JNICALL
Java_tech_itunz_jni_Jni_evaluate(JNIEnv *env, jobject obj, jstring form)
{
    const char *pformChar = env->GetStringUTFChars(form, NULL);
    std::vector<Token> tokenVec;
    unsigned int count = 0;
    /*for (const char *p = pformChar; *p != 0; p++)
      std::cin.putback(*p);*/
    std::string instr{pformChar};
    instr += ";";
    std::istringstream istr{instr};
    takeIn(tokenVec, istr);
    double num = add_sub(tokenVec, count);
    return (jdouble) num;
}