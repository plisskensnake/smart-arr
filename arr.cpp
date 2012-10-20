#include <stdlib.h>
#include <stdio.h>
#include "smartarray.h"





int main(int argc, const char **argv) {
	int is=4; int js=3; int ks=4;
	Set s(3,is,js,ks);
	smartArray<int> a(s);
	int t=0;
	for(int i=0;i<is;i++) {
		for(int j=0;j<js;j++) {
			for(int k=0;k<ks;k++) {
				Set s0(3,i,j,k);
				a[s0]=t;
				printf("a[%d,%d,%d]=%d\n",i,j,k,t);
				t++;
			}
		}
	}
	printf("\n");
	for(int i=0;i<is;i++) {
		for(int j=0;j<js;j++) {
			for(int k=0;k<ks;k++) {
				Set s0(3,i,j,k);
				printf("a[%d,%d,%d]=%d\n",i,j,k,a[s0]);
			}
		}
	}
	printf("\n");
	t=40;
	Set s1(2,is,js);
	smartArray<char> b(s1);
	for(int i=0;i<is;i++) {
		for(int j=0;j<js;j++) {
			Set s0(2,i,j);
				printf("b[%d,%d]=%c\n",i,j,(char)t);
				b[s0]=(char)t;				
				t++;
		}
	}
	printf("\n");
	for(int i=0;i<is;i++) {
		for(int j=0;j<js;j++) {
			Set s0(2,i,j);
				printf("b[%d,%d]=%c\n",i,j,b[s0]);
		}
	}
	
	try{
		Set tmp(2,10,10);
		a[tmp];
	} catch (const char* mes) {
		printf("%s\n",mes);
	}
	
	try{
		Set tmp(3,10,10,10);
		a[tmp];
	} catch (const char* mes) {
		printf("%s\n",mes);
	}
	
	return 0;
}
