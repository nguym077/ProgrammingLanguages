// Marian Nguyen
// Homework 4

// Problem 4 -- Write the following F# functions

// (a) compare x y: given two integers 'x' and 'y',
//     if x < y, return a negative integer
//     if x == 0, return 0
//     if x > y, return positive integer 
let compare x y =
    if x = 0 then
        0
    elif x < y then
        -1
    else
        1
// type: int -> int -> int

// (b) filter pred coll: given a predicate function 'pred', return a 
//     list containing all elements of 'coll' that satisfy the predicate function
let rec isEven x =
    if x % 2 = 0 then
        true
    else
        false

let rec filter pred coll =
    if List.isEmpty coll then
        []
    elif pred (List.head coll) then
        List.head coll :: filter pred (List.tail coll)
    else
        filter pred (List.tail coll)
// type: (a' -> bool) -> a' list -> a' list

// (c) butlast coll: return a list that contains all elements of the given
//     list except the last element, or [] if the list is empty
let rec butlast coll =
    match coll with
    | [] -> []
    | [h] -> []                 // if theres only one element in list
    | h::t -> h::butlast t      // if there are 2 or more elements
// type: a' list -> a' list

// (d) countEvens coll: given a list of integers, return the number
//     of even values in the list.
let rec countEvens coll =
    match coll with
    | []                  -> 0
    | h::t when h % 2 = 0 -> 1 + countEvens t
    | h::t                -> countEvens t
// type: int list -> int


[<EntryPoint>]
let main argv = 
    let list = [1;2;3;4;5;6]
    let x = filter isEven list

    let y = butlast list

    0 // return an integer exit code