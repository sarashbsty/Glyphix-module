/*
Copyright (c) 2025 Sarash Basumatary 

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include<iostream>
#include<string.h>
#include "glyphix.h"
#include "cJSON.h"
using namespace std;

static char* createJson(int error, const char *errorMsg, const char *text){
	cJSON* outputRoot = cJSON_CreateObject();
	cJSON_AddBoolToObject(outputRoot, "error" , error);
	cJSON_AddStringToObject(outputRoot, "errorMsg" , errorMsg);
	cJSON_AddStringToObject(outputRoot, "text", text);
	char* outputJson = cJSON_Print(outputRoot);
	cJSON_Delete(outputRoot);
	return outputJson;
}

extern "C"{
	char* run_glyphix(const char* json_text)
	{
		cJSON *inputRoot = cJSON_Parse(json_text);

		if(!inputRoot) return createJson(1, "Parsing Failed", "");

		cJSON *sizeJson = cJSON_GetObjectItem(inputRoot, "size");
		cJSON *textJson = cJSON_GetObjectItem(inputRoot, "text");
		cJSON *styleJson = cJSON_GetObjectItem(inputRoot, "style");

		//Input Validation: phase 1
		if(!cJSON_IsNumber(sizeJson) || !cJSON_IsString(textJson) ||
		!cJSON_IsString(styleJson) || strlen(styleJson->valuestring) != 1)
		{
			cJSON_Delete(inputRoot);
			return createJson(1, "Invalid Inputs", "");
		}    

		int size = sizeJson->valueint;
		string text = textJson->valuestring;
		char style = styleJson->valuestring[0];
		cJSON_Delete(inputRoot);
		
		//Input Validation: phase 2
		if(size < 5) return createJson(1, "Size smaller than 5 given", "");
		if(text.length() == 0) return createJson(1, "Empty text given", "");
		for(int i = 0; i < text.length(); i++){
			char ch = text[i];
			if((ch < 'a' || ch > 'z') && (ch < 'A' || ch > 'Z') && ch != ' ')
				return createJson(1, "Given text has non-alphabetic Character", "");
		}

		string out = glyphix(text, size, style);
		return createJson(0, "", out.c_str());
	}

	void free_json(char *ptr){
		cJSON_free(ptr);
	}
}

int main(){
	const char* jsonText = R"({"size" : 4 , "text" : "A" , "style" : "~"})";
	cout<<"Input Json: "<<jsonText;
	cout<<"\n\noutput JSON:\n"<<run_glyphix(jsonText);
}