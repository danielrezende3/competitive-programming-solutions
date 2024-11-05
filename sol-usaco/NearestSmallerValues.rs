use std::io::{self, BufRead};

fn process_input<R: BufRead>(reader: R) -> (usize, Vec<i32>) {
    let mut lines = reader.lines();

    // Read the first line to get the size of the array
    let n = lines
        .next()
        .expect("No input found")
        .expect("Failed to read line")
        .trim()
        .parse::<usize>()
        .expect("Failed to parse the size of the array");

    // Read the second line to get the array values
    let array: Vec<i32> = lines
        .next()
        .expect("Missing array line")
        .expect("Failed to read line")
        .trim()
        .split_whitespace()
        .map(|x| x.parse::<i32>().expect("Failed to parse array element"))
        .collect();

    (n, array)
}

fn nearest_smaller_values_inefficient(n: usize, array: Vec<i32>) -> Vec<i32> {
    let mut response: Vec<i32> = Vec::new();
    for curr_size in 1..(n + 1) {
        let mut curr_stack = array[0..curr_size].to_vec(); // The problem lies on the copying here

        let to_be_compared = curr_stack.pop().unwrap();
        while curr_stack.len() > 0 {
            let maybe = curr_stack.len() as i32;
            let value = curr_stack.pop().unwrap();
            if value < to_be_compared {
                response.push(maybe);
                break;
            }
        }

        if response.len() != curr_size {
            response.push(0);
            continue;
        }
    }

    response
}

fn nearest_smaller_values(n: usize, array: Vec<i32>) -> Vec<i32> {
    let mut response: Vec<i32> = vec![0; n];
    let mut stack: Vec<(i32, usize)> = Vec::new();
    for i in 0..n {
        while let Some(&(value, index)) = stack.last() {
            if value < array[i] {
                response[i] = (index + 1) as i32;
                break;
            }
            stack.pop();
        }
        stack.push((array[i], i));
    }

    response
}

fn main() {
    let (n, array) = process_input(io::stdin().lock());
    let response: Vec<i32> = nearest_smaller_values(n, array);

    for (i, value) in response.iter().enumerate() {
        if i > 0 {
            print!(" ");
        }
        print!("{}", value);
    }
    println!();
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::io::Cursor;

    #[test]
    fn test_reading_input() {
        let input = "8\n2 5 1 4 8 3 2 5\n";
        let cursor = Cursor::new(input);

        let (n, array) = process_input(cursor);

        assert_eq!(n, 8);
        assert_eq!(array, vec![2, 5, 1, 4, 8, 3, 2, 5]);
    }

    #[test]
    fn test_2() {
        let input = vec![2, 5, 1, 4, 8, 3, 2, 5];
        let output = nearest_smaller_values(input.len(), input);
        let expected = vec![0, 1, 0, 3, 4, 3, 3, 7];
        assert_eq!(output, expected);
    }
    #[test]
    fn test_3() {
        let input = vec![1, 10, 9, 8, 7, 6, 5, 4, 3, 2];
        let output = nearest_smaller_values(input.len(), input);
        let expected = vec![0, 1, 1, 1, 1, 1, 1, 1, 1, 1];
        assert_eq!(output, expected);
    }
}
