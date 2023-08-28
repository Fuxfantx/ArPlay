#define LIB_NAME "PartialEase"
#define MODULE_NAME "PartialEase"

#define SINE_TABLE_SIZE 256
#define SINE_TABLE_SIZE1 255
#define PI 3.14159265358979323846
#define IPI 1.57079632679489661923
#define DPI 6.28318530717958647692

#if 2147483647L+1L == -2147483648L 
typedef long i32;
typedef unsigned long u32;
#else
typedef int i32;           /* In 64-bit systems, long may be 64-bit, */
typedef unsigned int u32; /* here we force it to be 32-bit. */
#endif

// include the Defold SDK
#include <dmsdk/sdk.h>

static const double sineTable[SINE_TABLE_SIZE] = {
	0.0,
	0.024541228522912288,
	0.049067674327418015,
	0.073564563599667426,
	0.098017140329560604,
	0.1224106751992162,
	0.14673047445536175,
	0.17096188876030122,
	0.19509032201612825,
	0.2191012401568698,
	0.24298017990326387,
	0.26671275747489837,
	0.29028467725446233,
	0.31368174039889152,
	0.33688985339222005,
	0.35989503653498811,
	0.38268343236508978,
	0.40524131400498986,
	0.42755509343028208,
	0.44961132965460654,
	0.47139673682599764,
	0.49289819222978404,
	0.51410274419322166,
	0.53499761988709715,
	0.55557023301960218,
	0.57580819141784534,
	0.59569930449243336,
	0.61523159058062682,
	0.63439328416364549,
	0.65317284295377676,
	0.67155895484701833,
	0.68954054473706683,
	0.70710678118654746,
	0.72424708295146689,
	0.74095112535495911,
	0.75720884650648446,
	0.77301045336273699,
	0.78834642762660623,
	0.80320753148064483,
	0.81758481315158371,
	0.83146961230254524,
	0.84485356524970701,
	0.85772861000027212,
	0.87008699110871135,
	0.88192126434835494,
	0.89322430119551532,
	0.90398929312344334,
	0.91420975570353069,
	0.92387953251128674,
	0.93299279883473885,
	0.94154406518302081,
	0.94952818059303667,
	0.95694033573220894,
	0.96377606579543984,
	0.97003125319454397,
	0.97570213003852857,
	0.98078528040323043,
	0.98527764238894122,
	0.98917650996478101,
	0.99247953459870997,
	0.99518472667219682,
	0.99729045667869021,
	0.99879545620517241,
	0.99969881869620425,
	1.0,
	0.99969881869620425,
	0.99879545620517241,
	0.99729045667869021,
	0.99518472667219693,
	0.99247953459870997,
	0.98917650996478101,
	0.98527764238894122,
	0.98078528040323043,
	0.97570213003852857,
	0.97003125319454397,
	0.96377606579543984,
	0.95694033573220894,
	0.94952818059303667,
	0.94154406518302081,
	0.93299279883473885,
	0.92387953251128674,
	0.91420975570353069,
	0.90398929312344345,
	0.89322430119551521,
	0.88192126434835505,
	0.87008699110871146,
	0.85772861000027212,
	0.84485356524970723,
	0.83146961230254546,
	0.81758481315158371,
	0.80320753148064494,
	0.78834642762660634,
	0.7730104533627371,
	0.75720884650648468,
	0.74095112535495899,
	0.72424708295146689,
	0.70710678118654757,
	0.68954054473706705,
	0.67155895484701855,
	0.65317284295377664,
	0.63439328416364549,
	0.61523159058062693,
	0.59569930449243347,
	0.57580819141784545,
	0.55557023301960218,
	0.53499761988709715,
	0.51410274419322177,
	0.49289819222978415,
	0.47139673682599786,
	0.44961132965460687,
	0.42755509343028203,
	0.40524131400498992,
	0.38268343236508989,
	0.35989503653498833,
	0.33688985339222033,
	0.31368174039889141,
	0.29028467725446239,
	0.26671275747489848,
	0.24298017990326407,
	0.21910124015687005,
	0.19509032201612861,
	0.17096188876030122,
	0.1467304744553618,
	0.12241067519921635,
	0.098017140329560826,
	0.073564563599667732,
	0.049067674327417966,
	0.024541228522912326,
	0.0,
	-0.02454122852291208,
	-0.049067674327417724,
	-0.073564563599667496,
	-0.09801714032956059,
	-0.1224106751992161,
	-0.14673047445536158,
	-0.17096188876030097,
	-0.19509032201612836,
	-0.2191012401568698,
	-0.24298017990326382,
	-0.26671275747489825,
	-0.29028467725446211,
	-0.31368174039889118,
	-0.33688985339222011,
	-0.35989503653498811,
	-0.38268343236508967,
	-0.40524131400498969,
	-0.42755509343028181,
	-0.44961132965460665,
	-0.47139673682599764,
	-0.49289819222978393,
	-0.51410274419322155,
	-0.53499761988709693,
	-0.55557023301960196,
	-0.57580819141784534,
	-0.59569930449243325,
	-0.61523159058062671,
	-0.63439328416364527,
	-0.65317284295377653,
	-0.67155895484701844,
	-0.68954054473706683,
	-0.70710678118654746,
	-0.72424708295146678,
	-0.74095112535495888,
	-0.75720884650648423,
	-0.77301045336273666,
	-0.78834642762660589,
	-0.80320753148064505,
	-0.81758481315158382,
	-0.83146961230254524,
	-0.84485356524970701,
	-0.85772861000027201,
	-0.87008699110871135,
	-0.88192126434835494,
	-0.89322430119551521,
	-0.90398929312344312,
	-0.91420975570353047,
	-0.92387953251128652,
	-0.93299279883473896,
	-0.94154406518302081,
	-0.94952818059303667,
	-0.95694033573220882,
	-0.96377606579543984,
	-0.97003125319454397,
	-0.97570213003852846,
	-0.98078528040323032,
	-0.98527764238894111,
	-0.9891765099647809,
	-0.99247953459871008,
	-0.99518472667219693,
	-0.99729045667869021,
	-0.99879545620517241,
	-0.99969881869620425,
	-1.0,
	-0.99969881869620425,
	-0.99879545620517241,
	-0.99729045667869021,
	-0.99518472667219693,
	-0.99247953459871008,
	-0.9891765099647809,
	-0.98527764238894122,
	-0.98078528040323043,
	-0.97570213003852857,
	-0.97003125319454397,
	-0.96377606579543995,
	-0.95694033573220894,
	-0.94952818059303679,
	-0.94154406518302092,
	-0.93299279883473907,
	-0.92387953251128663,
	-0.91420975570353058,
	-0.90398929312344334,
	-0.89322430119551532,
	-0.88192126434835505,
	-0.87008699110871146,
	-0.85772861000027223,
	-0.84485356524970723,
	-0.83146961230254546,
	-0.81758481315158404,
	-0.80320753148064528,
	-0.78834642762660612,
	-0.77301045336273688,
	-0.75720884650648457,
	-0.74095112535495911,
	-0.724247082951467,
	-0.70710678118654768,
	-0.68954054473706716,
	-0.67155895484701866,
	-0.65317284295377709,
	-0.63439328416364593,
	-0.61523159058062737,
	-0.59569930449243325,
	-0.57580819141784523,
	-0.55557023301960218,
	-0.53499761988709726,
	-0.51410274419322188,
	-0.49289819222978426,
	-0.47139673682599792,
	-0.44961132965460698,
	-0.42755509343028253,
	-0.40524131400499042,
	-0.38268343236509039,
	-0.359895036534988,
	-0.33688985339222,
	-0.31368174039889152,
	-0.2902846772544625,
	-0.26671275747489859,
	-0.24298017990326418,
	-0.21910124015687016,
	-0.19509032201612872,
	-0.17096188876030177,
	-0.14673047445536239,
	-0.12241067519921603,
	-0.098017140329560506,
	-0.073564563599667412,
	-0.049067674327418091,
	-0.024541228522912448
};

// fast_sin by Marc Pony(marc_pony@163.com)
static inline double ArSin(double x)
{
	// int sign = x > 0.0 ? 1 : -1;
	// int si = (int)(x * SINE_TABLE_SIZE / (2.0 * PI) + sign * 0.5);
	int si = (int)(x * SINE_TABLE_SIZE / DPI + 0.5);
	double d = x - si * (DPI / SINE_TABLE_SIZE);
	int ci = si + (SINE_TABLE_SIZE >> 2);
	si &= (SINE_TABLE_SIZE1);
	ci &= (SINE_TABLE_SIZE1);
	return sineTable[si] + (sineTable[ci] - 0.5 * sineTable[si] * d) * d;
}

// fast_cos by Marc Pony(marc_pony@163.com)
static inline double ArCos(double x)
{
	// int sign = x > 0.0 ? 1 : -1;
	// int ci = (int)(x * SINE_TABLE_SIZE / (2.0 * PI) + sign * 0.5);
	int ci = (int)(x * SINE_TABLE_SIZE / DPI + 0.5);
	double d = x - ci * ( DPI / SINE_TABLE_SIZE);
	int si = ci + (SINE_TABLE_SIZE >> 2);
	si &= (SINE_TABLE_SIZE1);
	ci &= (SINE_TABLE_SIZE1);
	return sineTable[si] - (sineTable[ci] + 0.5 * sineTable[si] * d) * d;
}

// fast_sin by Marc Pony(marc_pony@163.com)
// Lua Version
static inline int Sin(lua_State* L)
{
	lua_Number x = lua_tonumber(L, 1);
	double d = x > 0.0 ? 0.5 : -0.5;
	int si = (int)(x * SINE_TABLE_SIZE / DPI + d);
	int ci = si + (SINE_TABLE_SIZE >> 2);
	d = x - si * (DPI / SINE_TABLE_SIZE);
	si &= (SINE_TABLE_SIZE1);
	ci &= (SINE_TABLE_SIZE1);

	DM_LUA_STACK_CHECK(L, 1);
	lua_pushnumber(L, sineTable[si] + (sineTable[ci] - 0.5 * sineTable[si] * d) * d );
	return 1;
}

// fast_cos by Marc Pony(marc_pony@163.com)
// Lua Version
static inline int Cos(lua_State* L)
{
	lua_Number x = lua_tonumber(L, 1);
	double d = x > 0.0 ? 0.5 : -0.5;
	int ci = (int)(x * SINE_TABLE_SIZE / DPI + d);
	int si = ci + (SINE_TABLE_SIZE >> 2);
	d = x - ci * (DPI / SINE_TABLE_SIZE) ;
	si &= (SINE_TABLE_SIZE1);
	ci &= (SINE_TABLE_SIZE1);

	DM_LUA_STACK_CHECK(L, 1);
	lua_pushnumber(L, sineTable[si] - (sineTable[ci] + 0.5 * sineTable[si] * d) * d );
	return 1;
}


// Functions exposed to Lua
static const luaL_reg Module_methods[] =
{
	{"Sin", Sin},
	{"Cos", Cos},
	{0, 0}
};

inline dmExtension::Result AcAppOK(dmExtension::AppParams* params) {return dmExtension::RESULT_OK;}
inline dmExtension::Result AcOK(dmExtension::Params* params) {return dmExtension::RESULT_OK;}
inline dmExtension::Result Initialize(dmExtension::Params* params)
{
	luaL_register(params->m_L, MODULE_NAME, Module_methods);
	lua_pop(params->m_L, 1);
	return dmExtension::RESULT_OK;
}

DM_DECLARE_EXTENSION(PartialEase, LIB_NAME, AcAppOK, AcAppOK, Initialize, 0, 0, AcOK)