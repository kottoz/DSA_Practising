
fn greet_world()
{
    println!("Hello, World!!");
    let mut south_ger = "Gruss Gott";
    let mut japan = "ハロー・ワールド";

    let mut regions = [south_ger, japan];
    for region in regions.iter()
    {
        println!("{}", region);
    }
}

// test iterators
// fn test()
// {
//     let arr = [1, 2, 3];
//     let mut iterator = arr.iter();
//     println!("{:?}", iterator.next().unwrap());
// }

// fn change(some_string: &mut String)
// {
//     some_string.push_str(" World!");
// }


// fn test2()
// {
//     let mut s = String::from("hello");

//     let c1 = &s;
//     println!("{}", c1);
//     change(&mut s);
//     let c2 = &s;
//     println!("{}", c2);
// }


fn main() {
    greet_world();
}
