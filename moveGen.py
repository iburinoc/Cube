string = raw_input();
print '    cube* work0;' 
print '    cube* work1;'
print '    work0 = copy();'
num = '1'
onum = '0'
for char in string:
    if char == 'z':
        print'    work'+num+'=work'+onum+'->transform_roll_z();'
        print'    delete work'+onum+';'
        num, onum = onum, num
    elif char == 'x':
        print'    work'+num+'=work'+onum+'->transform_roll_x();'
        print'    delete work'+onum+';'
        num, onum = onum, num
    elif char == 'r':
        print'    work'+num+'=work'+onum+'->transform_rot_r();'
        print'    delete work'+onum+';'
        num, onum = onum, num
    elif char == 'l':
        print'    work'+num+'=work'+onum+'->transform_rot_l();'
        print'    delete work'+onum+';'
        num, onum = onum, num
print '    return work'+onum +';'
