function lengthOfLastWord(s: string): number {
    // We need to clip the white space
    const trimedS:string = s.trim()
    console.log(trimedS)

    // We need to convert sentence to array of words
    const arrayOFS: string[] = trimedS.split(" ")
    console.log(arrayOFS)

    // Get length of last worf
    const LAST_WORD_INDEX:number = arrayOFS.length-1
    const lastWordLength : number= arrayOFS[LAST_WORD_INDEX].length

    return lastWordLength
};
