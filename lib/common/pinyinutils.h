#ifndef PINYINUTILS_H
#define PINYINUTILS_H
#include <QString>
#include "lib_global.h"

static const int li_SecPosValue[] = { 1601, 1637, 1833, 2078, 2274,
            2302, 2433, 2594, 2787, 3106, 3212, 3472, 3635, 3722, 3730, 3858,
            4027, 4086, 4390, 4558, 4684, 4925, 5249, 5590 };

//字母Z使用了两个标签，这里有２７个值
//i, u, v都不做声母, 跟随前面的字母

static QString lc_FirstLetter [] =
{
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
    'S', 'T', 'W', 'X', 'Y', 'Z'
};

static const char alphatable[] =
{
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
    'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
    'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};

static QString ls_SecondSecTable = "cjwgnspgcgne[z[btzzzdxzkzgt[jnnjqmbsgzsczjszz"
        "[pgkbzgz[zwjkgkljzwkpjqhz[w[dzlsgmrzpzwwcckznkzzgttnjjnzkkzztcjnmczlqlzpzqfqrpzslwbtgkjfzxjwzltbncxjjjjtxdttsqzzcdxxhgck"
        "[phffss[zbgxlppbzll[hlxs[zm[jhsojnghdzqzklgjhsgqzhxqgkezzwzscscjxzezxadzpmdssmzjzqjzzc[j"
        "[wqjbzzpxgznzcpwhkxhqkmwfbpbzdtjzzkqhzlzgxfptzjzzzpszlfchmqshgmxxsxj["
        "[dcsbbqbefsjzhxwgzkpzlqbgldlcctnmazddkssngzcsgxlzzazbnptsdkdzlhgzmzlcxpz"
        "[jndqjwxqxfzzfjlejpzrxccqwqqsbnkzmgplbmjrqcflnzmzqmsqzrbcjthztqfrxqhxmjjcjlxqgjmshzkbswzemzltxfszdswlzcjqxsjnqbsctzhbftdczzdjwz"
        "ghqfrxwckqkxebptlpxjzsrmebwhjlbjslzzsmdxlclqkxlhxjrzjmfqhxhwzwsbhtrxxglhqhfnm[zkldzxzpzlgg[mtcfpajjzzljtzanjgbjplqgdzzqz"
        "axbkzsecjsznslzzhsxlzcghpxzhznztdsbcjkdlzazfmzdlebbgqzzkxgldndnzskjshdlzxbcghxzpkdjmmzngmmclgwzszxzjfznmlzzthcszdbdllscdd"
        "nlkjzkjszcjlkwhqasdknhcsganhdaashtcplcpqzbsdmpjlpzjoqlcdhjjzsprchn[nnlhlzzqzhwzptczgwwmzffjqqqqzxaclbhkdjxdgmmzdjxzllszgx"
        "gkjrzwzwzclzmssjzldbzd[fcxzhlxchzzjq[[qagmnzxpfrkssbjlzxzszglnscmhzwwmnzjjlxxhchsz[[ttxrzczxbzhcsmxjsznpwgpxxtazbgajcxlz"
        "[dccwzocwkccsbnhcpdzznfczztzckxkzbsqkkztqqxfcwchczkelzqbsqzjqcclmthszwhmktlkjlzcxwheqqhtqh[pq"
        "[qscfzmndmgbwhwlgsllzsdlmlxpthmjhwljzzhzjxhtxjlhxrswlwzjcbxmhzqxsdzpmgfcsglsxzmjshxpjxwmzqksmzplrthbxftpmhzxlchlhlzz"
        "lxgsssstclsldclrpbhzhxzzfhb[gdmzcnqqwlqhjj[zwjzzejjdhpblqxtqkwhlchqxagtlxljxmsl[htzkzjecxjcjnmfbz[sfzwzbjzgnzsdzsqzrslj"
        "pclpwxsdwejbjcbcnaztwgmpapclzqpclzxsbnmsggfnzjjbzsfzzndxhplqkzczwalsbccjx[zzgwkzpsgxfzfcdkhjgxdlqfsgdslqwzkxtmhsbgzmjzrglzj"
        "bpmlmsxlzjqqhzzjczzdjwbmzklddpmjegxzhzlxhlqzqhkzcwcjmzzxnatjhzccxzpcqlbzwwztwbqcmlpmzrjcccxfpznzzljplxxzztzlgdldcklzrzzgqtg"
        "jhhgjljaxfgfjzslcfdqzlclgjdjcsnzlljpjqdcclcjxmzzftsxgcgsbrzxjqqctzhgzqtjqqlzxjzlzlbczamcstzlpdjbzregklzzzhlzszqlznwczcllwjq"
        "jjjkdgjzolbbzppglghtgzxzghzmzcnqszczhbhgxkamtxzxnbskzzzgjzlqjdfcjxdzgjqjjpmgwgjjjpkqsbgbmmcjssclpqpdxcdzzkz[cjddzzgzwrhjrtgz"
        "nzqldkljszzgzqzjgdzkshpzmtlcpwnjafzzdjcnmwesczglbtzcgmssllzxqsxsbsjsbbsgghfjlzpmzjnlzzwdqshzxtzzwhmzzhzwdbxbtlmszzzfsxjc[dxx"
        "lhjhf[sxzqhfzmzcztqcxzxrttdjhnnzzqqmnqdmmg[zdxmjgdhcdzzbffallztdltfxmxqzdngwqdbdczjdxbzgsqqddjcmbkzffxmkdmdszzszcmljdsznsbrs"
        "kmkmpcklgdbqtfzswtfgglzplljzhgj[gzpzltcsmcnbtjbqfkthbzzgkpbbzmtdssxtbnpdklezcjnzddzkzddhqhsdzsctarlltkzlgecllkjlqjaqnbdkkghp"
        "jtzqksecshalqfmmgjnlzjbbtmlzzxdcjpldlpcqdhzzcbzsczbzmsljflkrzjsnfrgjhxpdhzjzbzgdlqcsezgxlblgzxtwmabchecmwzjzzlljjzhlg[djlslz"
        "gkdzpzxjzzzlwcxszfgwzzdlzhcljscmbjhblzzlzcblzdpdqzsxqzbztdkzxjz[cnrjmpdjgklcljbctbjddbblblczqrppxjcjlzcshltoljnmdddlngkaqhqh"
        "jgzkheznmshrp[qqjchgmfprxhjgdzchghlzrzqlczqjnzsqtkqjzmszswlcfqqqxzfggzptqwlmcrnfkkfszzlqbmqammmzxctpshcptxxzzsmphpshmclmldqf"
        "zqxszzzdzjzzhqpdszglstjbckbxzqzjsgpsxqzqzrqtbdkzxzkhhgflbcsmdldgdzdblzzzcxnncszbzbfglzzxswmsccmqnjqsbdqsjtxxmbltxzclzshzcxrq"
        "jgjzlxzfjphzmzqqzdfqjjlzznzjcdgzzgctxmzzsctlkphtxhtlbjxjlxscdqxcbbtjfqzfsltjbtkqbxxjjljchczdbzjdczjdcprnpqcjpfczlclzxzdmxmph"
        "jsgzgszzqlzlwtjpfszasmcjbtzkzcwmztcsjjljcqlwzmalbxzfbpnlsfhtgjwejjxxglljstgshjqlzfkcgnnnszfdeqfhbsaqtgzlbxmmzgszldzdqmjjrgbj"
        "tkgdhgkblqkbdmbzlxwcxzttzbkmrtjzxqjbhlmhmjjzmqasldczxzqdlqcafzwzxqhz";

class LIBSHARED_EXPORT PinYinUtils
{
public:
    PinYinUtils();
    ~PinYinUtils();
    char Char2Alpha(QChar ch);
    QString String2Alpha(QString SourceStr);
    int gbValue(QString ch);

    static QString conversionStr(QString str, const char *charsetName,const char *toCharsetName);
    static QString getFirstLetter(QString chinese);
    static QString getAllFirstLetter(QString str);
private:
    int table[27];

    bool match(int i, int gb);
};

#endif // PINYINUTILS_H
