// rust standard library comes with env module.
// env module contains functions to inspect various aspects such as environment variables,
// process arguments, the current directory, and various other important directories.
use std::env::{args, Args};

fn main() {
    let mut args: Args = args();
    let first = args.nth(1).unwrap();
    let operator = args.nth(0).unwrap().chars().next().unwrap();
    let third = args.nth(0).unwrap();

    // let first_number: f32 = first.parse().unwrap();          // use annotating to the conversion.
    let _first_number = first.parse::<f32>().unwrap(); // use turbofish to convert string to another type.
                                                       // let second_number: f32 = third.parse().unwrap();
    let _second_number = third.parse::<f32>().unwrap();

    // let operator = second.parse::<char>().unwrap();

    let result: f32 = operate(operator, _first_number, _second_number);

    println!("{}", result);
}

fn operate(operator: char, first_number: f32, second_number: f32) -> f32 {
    if operator == '+' {
        first_number + second_number
    } else if operator == '-' {
        first_number - second_number
    } else if operator == '*' {
        first_number * second_number
    } else if operator == '/' {
        first_number / second_number
    } else {
        0.0
    }
}
