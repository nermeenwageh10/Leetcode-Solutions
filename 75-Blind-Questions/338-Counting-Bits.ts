function countBits(n: number): number[] {
    const arr: number[] = [0];
    for (let i = 1; i <= n; i++) {
      const value = i.toString(2).split('1').length - 1;
      arr.push(value);
    }
    return arr;
};
