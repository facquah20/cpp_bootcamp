#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "Math.h"



void prompt_user_to_initialize_values(float &,float &,float &);

float calculate_amount_of_nuclide_remaining(float &,float ,float &);

void prompt_user_to_enter_output_filename(std::string &file){
    std::cout<<"Enter the name of the output file: ";
    std::cin>>file;
}

void print_app_info();


int main(){

    Math::x;
    Science::x;
    print_app_info();
    
    float initial_amount_of_radionuclide = 0.0; //amount in grammes
    float duration_of_decay = 0.0; // in seconds
    float decay_constant; //unit of per seconds

    //initialize the values
    prompt_user_to_initialize_values(initial_amount_of_radionuclide,duration_of_decay,
    decay_constant);

    /* allow the user to specify the name of the file to output the result */
    std::string result_file;
    prompt_user_to_enter_output_filename(result_file);

    /* outputing the result to the file */
    const float number_per_time = duration_of_decay/200;
    float total_time = 0;
    //float *p_total_time = &total_time;

    std::ofstream file(result_file);
    file<<"Amount(g)"<<std::setw(10)<<"time (sec)"<<std::endl;

    while(total_time<duration_of_decay){
        float remained = calculate_amount_of_nuclide_remaining(initial_amount_of_radionuclide,total_time,decay_constant);
        file<<remained<<std::setw(10)<<total_time<<std::endl;
        // std::cout<<"Amount_left: "<<remained<<std::endl;
        // std::cout<<"Time: "<<total_time<<std::endl;

        total_time+=number_per_time;
    }
    file.close(); //close the file
    std::cout<<"Check "<<result_file<<" "<<"for your result\n\n";
    std::cout<<"-------------DONE-------------------\n";
    return 1;

}

void prompt_user_to_initialize_values(float &initial_amount,float &duration,
float &decay_constant){

    std::cout<<"Enter initial amount of radionuclide(grammes): ";
    std::cin>>initial_amount;

    std::cout<<"Enter the duration for the decay (seconds): ";
    std::cin>>duration;
    
    std::cout<<"Enter the value of the decay constant (per second): ";
    std::cin>>decay_constant;

    std::cout<<"---The values have successfully been initialized--\n";
}


float calculate_amount_of_nuclide_remaining(float &initial_amount,float time,
float &decay_constant){
    return initial_amount*exp(-time*decay_constant);
}

void print_app_info(){
    std::cout<<"---RADIOACTIVE DECAY ANALYSIS-----\n\n";
    std::cout<<"Initialise the required values\n";
}

