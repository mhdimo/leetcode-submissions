var TimeLimitedCache = function() {
    this.size = 0;
    this.cache = {};
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {

    let returnValue;

    if(this.cache.hasOwnProperty(key) && this.cache[key].expired === false) {
        clearTimeout(this.cache[key].timeout)
        returnValue = true;
    } else {
        returnValue = false;
        this.size++;
    }

    this.cache[key] = {
        value: value,
        expired: false,
        timeout: setTimeout(() =>{
            this.cache[key].expired = true;
            this.size--;
        }, duration)
    }

    return returnValue;
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    if (this.cache[key]?.expired === false){
        return this.cache[key].value;
    } else {
        return -1;
    }
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
    return this.size;
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */