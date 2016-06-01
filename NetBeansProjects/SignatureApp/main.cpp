/* 
 * File:   main.cpp
 * Author: doctus
 *
 * Created on 1 Июнь 2016 г., 7:27
 */

#include <cstdlib>
#include <string.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void getTest(std::string filename, std::string base){
    std::cout << "Loading file" << std::endl;
    FILE* file =  fopen(filename.c_str(), "r");
    fseek(file,0,SEEK_END);
    long file_size = ftell (file);
    fseek(file, 0, SEEK_SET);
    
    unsigned char * file_stream = (unsigned char *) malloc (sizeof(unsigned char) * file_size);
    fread(file_stream, sizeof(unsigned char), file_size / sizeof(unsigned char), file);
    
    char *sign = (char*)base.c_str();
    int count = 0;
    for(int i = 0; sign[i] != '\0' ;i++){
        if(sign[i] == ' '){
            for(int j = i;; j++){
                sign[j] = sign[j+1];
                if(sign[j] == '\0') break;
            }
            i--;
        }
        if(sign[i] == '0' && sign[i+1] == 'x'){
            for(int j = i;; j += 2){
                sign[j] = sign[j+2];
                if(sign[j] != '\0'){
                    sign[j + 1] = sign[j+3];
                }else{
                    break;
                }
            }
            i--;
        }
    }
    char *last = (char*)malloc(sizeof(char)*strlen(sign));
    strcpy(last, sign);
    long sizer = 1;
    for(int i = 0; i <  strlen(last); i++){
        if(last[i] == '?'){
            count++;
            sizer *= 16;
            last[i] = '0';
        }
    }
    
    int i = 0;
    unsigned char *pat = (unsigned char*)malloc(sizeof(unsigned char)*strlen(last)/2);
    while(i < strlen(sign)){
        while(sign[i] != '?'){
            i++;
            if(i >= strlen(sign))return;
        }
        bool b1 = true;
        if(last[i] == '9'){
            last[i] += 8;
        }else if(last[i] == 'F'){
            last[i] -= 22;
            b1 = false;
        }else{
            last[i]++;
        }
        if(b1){
            i = 0;
            pat[0] = '\0';
            for(int j = 0; j < strlen(last); j += 2){
                unsigned char c;
                if((last[j] > 47) && (last[j] < 58)){
                    c = 16 * (last[j] - 48);
                }else{
                    c = 16 * (last[j] - 55);
                }
                if((last[j + 1] > 47) && (last[j + 1] < 58)){
                    c += (last[j] - 48);
                }else{
                    c += (last[j] - 55);
                }
                pat[j/2] = c;
            }
            int l = 0;
            for(long k; k < file_size; k++){
                while(pat[l] == file_stream[k]){
                    l++;
                    k++;
                    if(l >= strlen(last)/2){
                        std::cout << (k - l) << std::endl;
                        return;
                    }
                }
                k -= l;
                l = 0;
            }
        }else{
            i++;
        }
    }
}
/*
 * 
 */
int main(int argc, char** argv) {
    getTest("/home/doctus/Downloads/test", "0xF0 0x01 0x?D");
    return 0;
}

