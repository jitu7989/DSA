struct Solution;
impl Solution {

    pub fn get_permutation(n: i32, k: i32) -> String {
        let mut p = k;
        let mut result: String = String::new();
        let mut factorial = [1 as usize; 10];
        let mut used = Vec::new();

        if n == 1 || p == 1 {
            for i in 1..=n {
                result.push_str(&i.to_string());
            }
            return result;
        }
        for i in 1..=n {
            used.push(i);
        }
        for i in 1..10 {
            factorial[i as usize] = factorial[(i as usize) - 1] * i;
        }

        for i in (2..=n as usize).rev() {
            let factorial = factorial[i - 1] as i32;
            let mut element_no = p / factorial;
            if p % factorial == 0 {
                element_no -= 1;
            }
            result.push_str(&used.remove(element_no as usize).to_string());
            p -= element_no * factorial;
        }
        result.push_str(&used.remove(0).to_string());


        return result;
    }
}