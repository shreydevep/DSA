/**
 * @param {string} s
 * @return {number}
 */
const parseString = (s)=>{
    return s.trim().split(" ").splice(-1)[0].length;
    
} 
var lengthOfLastWord = function(s) {
    return parseString(s);
    
};