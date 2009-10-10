# vim: ft=python expandtab
import os
from site_init import GBuilder, GInitialize

opts = Variables()
opts.Add(PathVariable('PREFIX', 'Installation prefix', os.path.expanduser('~/FOSS'), PathVariable.PathIsDirCreate))
opts.Add(BoolVariable('DEBUG', 'Build with Debugging information', 0))
opts.Add(PathVariable('PERL', 'Path to the executable perl', r'C:\Perl\bin\perl.exe', PathVariable.PathIsFile))

env = Environment(variables = opts,
                  ENV=os.environ, tools = ['default', GBuilder])
GInitialize(env)
env['ESCAPED_PREFIX'] = env['PREFIX'].replace('\\', '\\\\')

GTK_MAJOR_VERSION=2
GTK_MINOR_VERSION=18
GTK_MICRO_VERSION=2
GTK_INTERFACE_AGE=2
GTK_BINARY_AGE=GTK_MINOR_VERSION * 100 + GTK_MICRO_VERSION
GTK_API_VERSION='2.0'
GTK_BINARY_VERSION='2.10.0'
GTK_VERSION="%d.%d.%d" % (GTK_MAJOR_VERSION, GTK_MINOR_VERSION, GTK_MICRO_VERSION)
env['GTK_VERSION'] = GTK_VERSION
env['GTK_BINARY_VERSION'] = GTK_BINARY_VERSION
env['DOT_IN_SUBS'] = {'@PACKAGE_VERSION@': GTK_VERSION,
		      '@VERSION@': GTK_VERSION,
                      '@GTK_MAJOR_VERSION@': str(GTK_MAJOR_VERSION),
                      '@GTK_MINOR_VERSION@': str(GTK_MINOR_VERSION),
                      '@GTK_MICRO_VERSION@': str(GTK_MICRO_VERSION),
                      '@GTK_VERSION@': GTK_VERSION,
                      '@GTK_INTERFACE_AGE@': str(GTK_INTERFACE_AGE),
                      '@GTK_BINARY_AGE@': str(GTK_BINARY_AGE),
                      '@GTK_API_VERSION@': GTK_API_VERSION,
                      '@GTK_BINARY_VERSION@': GTK_BINARY_VERSION,
                      '@prefix@': env['PREFIX'],
                      '@exec_prefix@': '${prefix}/bin',
                      '@libdir@': '${prefix}/lib',
                      '@includedir@': '${prefix}/include',
                      '@host@': 'i486-windows',
                      '@gdktarget@': 'win32',
                      '@GETTEXT_PACKAGE@': 'gtk20',
                      '@GDKPACKAGES@': 'pangocairo gio-2.0',
                      '@GTKPACKAGES@': 'atk'}
pcs = ('gdk-win32-2.0.pc',
       'gtk+-2.0.pc',
       'gdk-pixbuf-2.0.pc',
       'gail.pc')

for pc in pcs:
    if pc != 'gdk-win32-2.0.pc':
        env.DotIn(pc, pc + '.in')
    else:
        env.DotIn(pc, 'gdk-2.0.pc.in')
    env.Alias('install', env.Install('$PREFIX/lib/pkgconfig', pc))

env.DotIn('config.h', 'config.h.win32.in')

env.AppendENVPath('PATH', env['PREFIX'] + '\\bin')

subdirs = ['gdk-pixbuf/SConscript',
           'gdk/SConscript',
           'gtk/SConscript',
           'modules/SConscript']
if ARGUMENTS.get('build_test', 0):
    subdirs += ['tests/SConscript',
                'demos/SConscript']

env.ParseConfig('pkg-config gio-2.0 --cflags --libs')
env.ParseConfig('pkg-config pangowin32 --cflags --libs')
env.ParseConfig('pkg-config pangocairo --cflags --libs')
env.ParseConfig('pkg-config atk --cflags --libs')

SConscript(subdirs, exports=['env'])
