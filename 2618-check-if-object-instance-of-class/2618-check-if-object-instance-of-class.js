/**
 * @param {Object} object
 * @param {Function} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function(obj, classFunction) {
  if (obj === null || obj == undefined || classFunction == undefined || classFunction == null) return false;
  return obj.constructor === classFunction || checkIfInstanceOf(Object.getPrototypeOf(obj), classFunction);
};


/**
 * checkIfInstanceOf(new Date(), Date); // true
 */