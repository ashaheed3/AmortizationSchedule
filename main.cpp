/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: LungsSoMuddy
 *
 * Created on October 25, 2016, 11:12 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <math.h>

using namespace std;

float calcMonthlyPay (int initBal, float intRate, int payPer){
    return initBal *( (intRate*(pow((1+intRate),payPer)))/(pow((1+intRate),payPer)-1));
}





int main() {
    int numOfPay, i = 1;
    float loanAmount, r, x, monthlyPay,paidPrin = 0, paidInter = 0, newBal = 0;
    
    printf("Enter amount of loan: ");
    scanf("%f", &loanAmount);
    
    printf("Enter interest rate per year: ");
    scanf("%f", &x);
    r = x/12/100;
    
    printf("Enter number of payments: ");
    scanf("%d", &numOfPay);
    
    monthlyPay = calcMonthlyPay(loanAmount, r, numOfPay);
    printf("Monthly payment should be %.2f",monthlyPay );
    
    
    printf("\n========================Amortization Schedule=======================");
    printf("\n# \t Payment \t Principal \t Interest \t Balance");
    
    newBal = loanAmount;
    int n;
    while ( i<= numOfPay){
        n = 1;
            paidPrin = newBal * r;
            paidInter = monthlyPay - paidPrin;
            newBal = newBal - paidInter;
            printf("\n%d \t %.2f \t %.2f \t\t %.2f \t\t %.2f ", n, monthlyPay, paidPrin, paidInter, newBal );
            i++;
    }
         
            
    
    
   
    
    return 0;
}



