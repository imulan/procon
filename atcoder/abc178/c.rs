#[allow(unused_imports)]
use std::cmp::*;

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

static MOD: i64 = 1_000_000_007;

fn mod_pow(mut x: i64, mut n: i64) -> i64 {
    let mut ret = 1;
    while n > 0 {
        if n & 1 == 1 {
            ret *= x;
            ret %= MOD;
        }
        x *= x;
        x %= MOD;
        n >>= 1;
    }
    ret
}

fn main() {
    input! {
        n: i64,
    }
    let u = mod_pow(10, n);
    let a = mod_pow(9, n);
    let b = mod_pow(8, n);
    let ans = (u - a - a + b + 2 * MOD) % MOD;

    println!("{}", ans);
}
