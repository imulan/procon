#[allow(unused_imports)]
use std::cmp::*;
#[allow(unused_imports)]
use std::collections::*;

macro_rules! input {
    (source = $s:expr, $($r:tt)*) => {
        let mut iter = $s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
    ($($r:tt)*) => {
        let s = {
            use std::io::Read;
            let mut s = String::new();
            std::io::stdin().read_to_string(&mut s).unwrap();
            s
        };
        let mut iter = s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
}

macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

macro_rules! read_value {
    ($iter:expr, ( $($t:tt),* )) => {
        ( $(read_value!($iter, $t)),* )
    };

    ($iter:expr, [ $t:tt ; $len:expr ]) => {
        (0..$len).map(|_| read_value!($iter, $t)).collect::<Vec<_>>()
    };

    ($iter:expr, chars) => {
        read_value!($iter, String).chars().collect::<Vec<char>>()
    };

    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };

    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

fn solve() -> Option<Vec<i32>> {
    input! {
        n: usize,
        a: [i32; n],
        b: [i32; n],
    }

    let mut ca = vec![0i32; n + 1];
    let mut cb = vec![0i32; n + 1];
    for i in 0..n {
        ca[a[i] as usize] += 1;
        cb[b[i] as usize] += 1;
    }

    for i in 1..=n {
        if (ca[i] + cb[i]) as usize > n {
            return None;
        }
    }
    for i in 0..n {
        ca[i + 1] += ca[i];
        cb[i + 1] += cb[i];
    }

    let mut s = 0;
    for i in 0..n {
        s = max(s, ca[i + 1] - cb[i]);
    }

    let mut ret = b.clone();
    ret.rotate_right(s as usize);
    Some(ret)
}

fn main() {
    match solve() {
        Some(x) => {
            println!("Yes");
            println!(
                "{}",
                x.iter()
                    .map(ToString::to_string)
                    .collect::<Vec<_>>()
                    .join(" ")
            );
        }
        None => {
            println!("No");
        }
    }
}
